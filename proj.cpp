#include <wx/wx.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/msgdlg.h>
#include <wx/choice.h>
#include <wx/statbox.h>
#include <wx/timer.h>
#include <unordered_map>
#include <wx/clipbrd.h>
#include <vector>
#include <algorithm>

class SearchFrame : public wxFrame
        {
public:
    SearchFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    void OnApplyFilters(wxCommandEvent& event);
    void OnCopyLink(wxCommandEvent& event);
    void OnSearch(wxCommandEvent& event);

    wxTextCtrl* searchInput;
    wxButton* applyButton;
    wxChoice* yearChoice;
    wxChoice* subjectChoice;
    wxChoice* semesterChoice;
    wxTextCtrl* linkDisplay;
    wxTextCtrl* questionDisplay;

    // Vector to store questions
    std::vector<wxString> questions;
};

SearchFrame::SearchFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size){

    // Example: Adding questions to the vector
    questions.push_back("Describe the complexomtery principle and procedure for the estimation of Mg2+ ions present in hard water.");
    questions.push_back("Compare COD and BOD of waste water. Explain the principle and titration procedure used for determination of chemically oxidisable impurities in industrial waste water.");
    questions.push_back("To find the of the given waste water sample, of it is diluted to in two separate bottles (labeled and ), saturated with oxygen and required additives for microorganisms. Only, the bottle- was incubated at for days. of diluted waste water from bottle- , reacts with and the same volume of diluted water from bottle- , reacts with of 2 2 3. Find the of the water sample.");
    questions.push_back("Highlight significance of the power alcohol, rocket propellants and\n"
                        "hydrogen fuels.");
    questions.push_back("Li ion battery could power future for e-mobility. Comment on it. With\n"
                        "a neatly described diagram, explain the design, working and reactions\n"
                        "of LiCoO2 battery.");
    questions.push_back("Explain the influence of pre-ignition and self-ignition on knocking of\n"
                        "IC engine.");
    questions.push_back("Discuss the principle, construction and functioning of DSSC with a\n"
                        "neatly labeled diagram.");
    questions.push_back("With a neatly labeled diagram and balanced redox reactions, explain\n"
                        "the construction and working of calomel electrode. Mention its\n"
                        "application.");
    questions.push_back("Write the reaction for the conversion of an oil into biodiesel. Highlight\n"
                        "its significance.");
    questions.push_back("Discuss the process of galvanization of iron sheets.");
    questions.push_back("Discuss the process of chromium plating. Mention its applications.");
    questions.push_back("Illustrate pitting and stress corrosion with suitable examples.");
    questions.push_back("Discuss the principle and procedure of solution combustion method\n"
                        "for the preparation of nanometal oxide nanoparticles.");
    questions.push_back("With a neat labeled diagram, and explain the procedure of CVD\n"
                        "method for the growth of CNTs. Highlight the role of important\n"
                        "components.");
    questions.push_back("Discuss the preparation of graphene by modified Hummer’s method,\n"
                        "Mention its applications.");
    questions.push_back("Highlight the significance of any two green chemistry principles.");
    questions.push_back("How is thermoplastic different than thermoset? Provide the synthesis\n"
                        "and industrial applications of polycarbonate.");
    questions.push_back("Provide the procedure for making polyaniline emeraldine salt and\n"
                        "highlight its applications.");
    questions.push_back("Compare and correlate the variation of with respect flexibility of\n"
                        "polymers with suitable examples.");
    questions.push_back("Write the polymer formation reactions of Epoxy resin. Mention any\n"
                        "two applications.");
    questions.push_back("How do you synthesize the poly lactic acid? Highlight its applications\n"
                        "in medicinal industry.");
    questions.push_back("What are self healing polymer? Illustrate the synthesis of silicone\n"
                        "rubber.");
    questions.push_back("Explain the procedure of determination of COD of sewage sample with\n"
                        "suitable reactions and calculations.");
    questions.push_back("Explain the construction and working of DSSC with neat labeled\n"
                        "diagram.");
    questions.push_back("In BOD analysis 25ml of water is diluted to 1000ml using dilution\n"
                        "water. BOD analysis at day 1 showed dissolved oxygen of 10mg and\n"
                        "dissolved oxygen at day 5 is 4mg. Calculate the BOD of the sample.");
    questions.push_back("Derive Nernst equation for single electrode considering\n"
                        "thermodynamic principle.");
    questions.push_back("Illustrate the construction and working of calomel electrode with neat\n"
                        "labeled diagram.");
    questions.push_back("A glass of calomel electrode assembly developed a potential of 0.46V\n"
                        "when it is dipped in the solution of pH 8. Same electrode system\n"
                        "developed a potential of 0.4V when it is dipped in unknown solution.\n"
                        "Calculate the pH of unknown solution (given Ecal=0.2412V).");
    questions.push_back("Explain the construction and working of lithium cobalt oxide battery\n"
                        "with neat labeled diagram along with the reactions involved during\n"
                        "charging and discharging.");
    questions.push_back("Explain the construction and working of methanol oxygen fuel cells.\n"
                        "And mention the role of anode and cathode catalysts used in the fuel\n"
                        "cells.");
    questions.push_back("What are the main differences between battery and fuel cells?");
    questions.push_back("An iron rod is kept in moist aerated environment. Discuss the\n"
                        "possible corrosion in above mentioned case and explain the rusting\n"
                        "process with necessary chemical reactions.");
    questions.push_back("What is electroplating? Explain the process of electroplating of\n"
                        "chromium.");
    questions.push_back("A welded wire mesh near a park area is exposed to atmosphere.\n"
                        "Discuss possible type of corrosion involved in it.");
    questions.push_back("Write any three factors affecting the rate of corrosion with relevant\n"
                        "applications.");
    questions.push_back("What are the main differences between electroplating and electro less\n"
                        "plating?");
    questions.push_back("Nano materials are very important for modern electronic industry.\n"
                        "Explain the synthesis of metal nano oxides using solution combustion\n"
                        "synthesis.");
    questions.push_back("Explain the synthesis of single layered graphene using modified\n"
                        "Hummer’s method.");
    questions.push_back("Illustrate the construction and working of flame photometer with\n"
                        "labeled diagram.");

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // Search bar
    wxBoxSizer* searchBarSizer = new wxBoxSizer(wxHORIZONTAL);
    searchInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, 0);
    applyButton = new wxButton(panel, wxID_ANY, "Search");

    searchBarSizer->Add(searchInput, 1, wxALL | wxALIGN_CENTER, 5);
    searchBarSizer->Add(applyButton, 0, wxALL | wxALIGN_CENTER, 5);

    // Filtering options
    wxStaticBoxSizer* filtersSizer = new wxStaticBoxSizer(wxVERTICAL, panel, "Filters");

    yearChoice = new wxChoice(panel, wxID_ANY);
    // Add year options to the choice
    yearChoice->Append("2019");
    yearChoice->Append("2020");
    yearChoice->Append("2021");
    yearChoice->Append("2022");
    yearChoice->Append("2023");

    subjectChoice = new wxChoice(panel, wxID_ANY);
    // Add subject options to the choice
    subjectChoice->Append("Math");
    subjectChoice->Append("Physics");
    subjectChoice->Append("Chemistry");
    subjectChoice->Append("Mechanical");
    subjectChoice->Append("Electrical");
    subjectChoice->Append("Electronics");
    subjectChoice->Append("Civil");
    subjectChoice->Append("C");

    semesterChoice = new wxChoice(panel, wxID_ANY);
    // Add semester options to the choice
    semesterChoice->Append("Semester 1");
    semesterChoice->Append("Semester 2");

    filtersSizer->Add(yearChoice, 0, wxALL | wxALIGN_CENTER, 5);
    filtersSizer->Add(subjectChoice, 0, wxALL | wxALIGN_CENTER, 5);
    filtersSizer->Add(semesterChoice, 0, wxALL | wxALIGN_CENTER, 5);

    // Link display area (wxTE_READONLY makes the text control read-only)
    linkDisplay = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_READONLY);

    // Question display area
    questionDisplay = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_MULTILINE);
    questionDisplay->SetMinSize(wxSize(-1, 100));

    // Button for applying filters
    applyButton = new wxButton(panel, wxID_ANY, "Apply Filters");

    // Button for copying the link to the clipboard
    wxButton* copyButton = new wxButton(panel, wxID_ANY, "Copy Link");

    mainSizer->Add(searchBarSizer, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(filtersSizer, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(linkDisplay, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(questionDisplay, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(applyButton, 0, wxALL | wxALIGN_RIGHT, 10);
    mainSizer->Add(copyButton, 0, wxALL | wxALIGN_RIGHT, 5);

    panel->SetSizer(mainSizer);

    Bind(wxEVT_BUTTON, &SearchFrame::OnApplyFilters, this, applyButton->GetId());
    Bind(wxEVT_BUTTON, &SearchFrame::OnCopyLink, this, copyButton->GetId());

    // Bind the search event
    Bind(wxEVT_TEXT, &SearchFrame::OnSearch, this, searchInput->GetId());
}

// Boyer-Moore search function
std::vector<int> BoyerMooreSearch(const wxString& haystack, const wxString& needle)
{
    std::vector<int> result;

    int m = needle.length();
    int n = haystack.length();

    if (m > n)
    {
        return result; // Empty result if needle is longer than haystack
    }

    // Calculate bad character heuristic
    std::vector<int> badChar(256, -1);
    for (int i = 0; i < m; i++)
    {
        badChar[needle[i]] = i;
    }

    int s = 0; // Shift of the pattern with respect to text
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && needle[j] == haystack[s + j])
        {
            j--;
        }

        if (j < 0)
        {
            // Needle found
            result.push_back(s);

            // Shift the pattern to find the next occurrence
            s += (s + m < n) ? m - badChar[haystack[s + m]] : 1;
        }
        else
        {
            // Shift based on bad character heuristic
            s += std::max(1, j - badChar[haystack[s + j]]);
        }
    }

    return result;
}

void SearchFrame::OnApplyFilters(wxCommandEvent& event)
{
    // Get selected options from filters
    wxString year = yearChoice->GetStringSelection();
    wxString subject = subjectChoice->GetStringSelection();
    wxString semester = semesterChoice->GetStringSelection();

    // Perform actions based on selected filters
    if (!year.IsEmpty() && !subject.IsEmpty() && !semester.IsEmpty())
    {
        // Check for specific conditions
        if (subject == "Math" &&  year == "2019" && semester == "Semester 1")
        {
            // If conditions are met, display a specific link
            wxString link = "https://drive.google.com/drive/folders/1jCpkbyrJCzPtu-bk4OTydi_ikMgiuxpL?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2020" && semester == "Semester 1")
        {
            wxString link = "https://drive.google.com/drive/folders/1MjFrbBzIDmb0PIgWhk2CAcDmlxzCRGeG?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2021" && semester == "Semester 1")
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2022" && semester == "Semester 1")
        {
            wxString link = "https://drive.google.com/drive/folders/1WWV3g0y0hoA-ufycxeSEoARjT5E3iC5q?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2023" && semester == "Semester 1")
        {
            wxString link = "https://drive.google.com/drive/folders/1gQLn-Ya_8eWrO3uo162klOjxVZ4_BKP_?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2019" && semester == "Semester 2")
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2020" && semester == "Semester 2")
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2021" && semester == "Semester 2")
        {
            wxString link = "https://drive.google.com/drive/folders/15aqg6_bSNZh_M86BsqK3WBQKKpTZlemN?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2022" && semester == "Semester 2")
        {
            wxString link = "https://drive.google.com/drive/folders/1FsWhpiIn2XibJRrl26vFFjINuKmxrYx_?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2023" && semester == "Semester 2")
        {
            wxString link = "https://drive.google.com/drive/folders/1h0T1yrVjOIrX7uaq42Sbb8VaxhgpPUAL?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Physics" && (year == "2023" || "2022" || "2021" || "2020" || "2019") && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1rCGL8AuHGhPwTPhf8ik57_dUt2o_DPpL?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Chemistry" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/196WzrGFSWR7lH6YFqMDevfKE8DxmWl9Q?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Chemistry" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Chemistry" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1YUJR7xV4ucNpnjCUABNIQNa7VMg4HtHK?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Chemistry" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1tCYHhNmDyq0tKNvaS0lDwPThHEtT-o_d?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Chemistry" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1lE_MxsmvzuEHMXPpvBCHbU5OKyBDL64_?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Mechanical" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1ePi8-XU8vBtp8KZM1zqbDRxV9lvYZqay?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Mechanical" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Mechanical" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/file/d/1Otf2qMADsYFMA24-FLbJMY7ExKCnpqlz/view?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Mechanical" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/file/d/1NwhYF_iTQXnjuaoUJxq39iUxt3cJ2LFM/view?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Mechanical" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1lMclhexRfs_Sk9U7E_LKH5REZ6lqD6I-?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electrical" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/file/d/1dmvSnDLXGKcdns_GP5PbW-xdOpDiBjX1/view?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electrical" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electrical" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/file/d/12H5GVtVtqT0_xbJz6AYDpZFpyRz_U3zc/view?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electrical" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1PZMpbcPIWDv-rlAN6OKKGagdFnNDpDqE?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electrical" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1Cx1916f9AjMloqkUp8RXSB3mOMr-aaEo?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electronics" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1zekK6P0kfaE6kSbIdse3d5q238CGiQD-?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electronics" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electronics" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/file/d/1hC00pm6bPXsqLnYNf22PzaZPQI0xEPii/view?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electronics" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1cRiWENN8kIlIFyENpz-E4cuduPzaNeOs?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electronics" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1sCfHfW0gwgytqs1-3GE8fXD3dx6Iu7l8?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Civil" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1K0d1q36_8fSsEAGh6ocLLnv7BTlJz1Wi?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Civil" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Civil" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/file/d/1oK8W8OtDzWIdUGyTkDBuYlhSUlPfFx6U/view?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Civil" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1qoRWWwLD48niQ6LFaX3F5JW5YzEOLfQA?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Civil" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/111EWZfAvS7b_5jQpdtYAPs00HGmLP8OY?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "C" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1BRK5A-8pK59613g_HknaLDq8WmC-9i39?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "C" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "C" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/1AIzL6nltIIZRYgozt_Mbeo3H1bCmxyBa?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "C" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/file/d/16J8t1C5tnU2DSVsV_PNtP7NtUrSAkU_d/view?usp=share_link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "C" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "https://drive.google.com/drive/folders/12adEx5uTvQp8PZO8jze5LQ6Dl93EGhPC?usp=share_link";
            linkDisplay->SetValue(link);
        }
    }
    else
    {
        // If any filter is not selected, display a message
        linkDisplay->SetValue("Please select all filters to generate a link.");
    }
}

void SearchFrame::OnCopyLink(wxCommandEvent& event)
{
    // Copy the link to the clipboard
    wxClipboard clipboard;
    clipboard.Open();
    clipboard.SetData(new wxTextDataObject(linkDisplay->GetValue()));
    clipboard.Close();

    wxMessageBox("Link copied to clipboard!", "Copy Link", wxOK | wxICON_INFORMATION);
}

void SearchFrame::OnSearch(wxCommandEvent& event)
{
    wxString keyword = searchInput->GetValue();

    // Check if the search bar is empty
    if (keyword.IsEmpty())
    {
        // If it's empty, clear the question display area
        questionDisplay->Clear();
        return;
    }

    // Filter questions based on the keyword using Boyer-Moore algorithm
    std::vector<wxString> matchingQuestions;
    for (const auto& q : questions)
    {
        if (!BoyerMooreSearch(q, keyword).empty())
        {
            matchingQuestions.push_back(q);
        }
    }

    // Display matching questions
    wxString result;
    for (const auto& q : matchingQuestions)
    {
        result += q + "\n";
    }

    questionDisplay->SetValue(result);
}

class VerificationFrame : public wxFrame
        {
public:
    VerificationFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    void OnVerify(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);

    wxTextCtrl* usnInput;
    std::unordered_map<wxString, wxString> usnData;

    SearchFrame* searchFrame;
};

VerificationFrame::VerificationFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size) {

    usnData["RVCE23BIS004"] = "Kaizer Dewaswala";
    usnData["RVCE23BIS018"] = "Manasa Krishnakumar";
    usnData["RVCE23BIS041"] = "Varenya Thaker";
    usnData["RVCE23BIS074"] = "SAMKIT SAMSUKHA";
    usnData["RVCE23BIS053"] = "OOJAM CHAUDHARY";
    usnData["RVCE23BIS066"] = "A A SIDDESHWARAN";
    usnData["RVCE23BIS034"] = "AADITYA S RAO";
    usnData["RVCE23BIS051"] = "AAKRISHT TIWARY";
    usnData["RVCE23BIS052"] = "AAYUSH PANDEY";
    usnData["RVCE23BIS136"] = "ABHISHEK S M";
    usnData["RVCE23BIS116"] = "ADITI SHASTRI";
    usnData["RVCE23BIS085"] = "ADITYA ANKANATH T R";
    usnData["RVCE23BIS127"] = "ADITYA KARUMBAIAH G U";
    usnData["RVCE23BIS097"] = "AISHWARYA SHET";
    usnData["RVCE23BIS010"] = "AKANKSHA RANI";
    usnData["RVCE23BIS102"] = "AKASH SIDDAPPA GOUNDI";
    usnData["RVCE23BIS079"] = "AKSHAT BHADORIA";
    usnData["RVCE23BIS110"] = "AKSHAY SHETTY";
    usnData["RVCE23BIS054"] = "ANGELA VARGHESE";
    usnData["RVCE23BIS047"] = "ANIRUDH C";
    usnData["RVCE23BIS078"] = "ANKIT KUMAR";
    usnData["RVCE23BIS145"] = "ANKIT PATHAK";
    usnData["RVCE23BIS020"] = "ANSHUMAN SRIVASTAV";
    usnData["RVCE23BIS058"] = "ANTRIKSH VATS";
    usnData["RVCE23BIS022"] = "ANURAG RATH";
    usnData["RVCE23BIS005"] = "APURVA N SANKOL";
    usnData["RVCE23BIS057"] = "ARSHIA SIROHI";
    usnData["RVCE23BIS042"] = "ARUNIMA ADHIKARI";
    usnData["RVCE23BIS119"] = "ARYA R";
    usnData["RVCE23BIS131"] = "ARYA SHETTY";
    usnData["RVCE23BIS037"] = "ASISH KUMAR YELETI";
    usnData["RVCE23BIS044"] = "ATHARVA AGARWAL";
    usnData["RVCE23BIS043"] = "AVANI SAKURIKAR";
    usnData["RVCE23BIS061"] = "AVNI JAIN";
    usnData["RVCE23BIS002"] = "AYUSH V MANGALGI";
    usnData["RVCE23BIS008"] = "B AMISHA PAI";
    usnData["RVCE23BIS075"] = "B S SRIVATSA";
    usnData["RVCE23BIS139"] = "BAGESH TALLOLLI";
    usnData["RVCE23BIS093"] = "BHARATH KUMAR M S";
    usnData["RVCE23BIS045"] = "BOBBITI KARTHIK REDDY";
    usnData["RVCE23BIS107"] = "BRAHATI JORAPUR";
    usnData["RVCE23BIS050"] = "CHALLA SAINADHA REDDY";
    usnData["RVCE23BIS121"] = "DAKSH MAYANK DESAI";
    usnData["RVCE23BIS103"] = "DEEKSHA NAIKAR";
    usnData["RVCE23BIS070"] = "DEEP SINGH DEO";
    usnData["RVCE23BIS026"] = "DEEPAK KUMAR N S";
    usnData["RVCE23BIS065"] = "DEV ABHISHEK";
    usnData["RVCE23BIS032"] = "DHANUSH P SHETTY";
    usnData["RVCE23BIS100"] = "DHARSHAN S N";
    usnData["RVCE23BIS114"] = "DHEERAJ R";
    usnData["RVCE23BIS111"] = "DHRUTHI D";
    usnData["RVCE23BIS039"] = "DHRUTHI RUDRANGI";
    usnData["RVCE23BIS071"] = "DHRUVA MARAVALALU RAVEENDRA";
    usnData["RVCE23BIS073"] = "EKAKSH AGRAWAL";
    usnData["RVCE23BIS099"] = "GANASHREE P M";
    usnData["RVCE23BIS049"] = "GAURI GAMINI SINGH";
    usnData["RVCE23BIS033"] = "HAMAAS SHABIR SHANGLOO";
    usnData["RVCE23BIS038"] = "HARSH DUBEY";
    usnData["RVCE23BIS024"] = "HAYAGRIV JAGANNATHAN";
    usnData["RVCE23BIS029"] = "JAGANMAYA M GIRI";
    usnData["RVCE23BIS101"] = "JASON ROHITH ALVA";
    usnData["RVCE23BIS095"] = "JEEVAN";
    usnData["RVCE23BIS113"] = "KARTHIK KRISHNAMURTI HEGDE";
    usnData["RVCE23BIS015"] = "KAVYA TRIVEDI";
    usnData["RVCE23BIS122"] = "KEERTHI M";
    usnData["RVCE23BIS017"] = "KOTRA SASANK";
    usnData["RVCE23BIS003"] = "KRISHNA";
    usnData["RVCE23BIS016"] = "KUSHAGRA BASHISTH";
    usnData["RVCE23BIS076"] = "MAHALAKSHMI B N";
    usnData["RVCE23BIS025"] = "MAHIKA MARPURI";
    usnData["RVCE23BIS030"] = "MANISH N";
    usnData["RVCE23BIS081"] = "MD ASIF ALI";
    usnData["RVCE23BIS132"] = "MEGHANA J L";
    usnData["RVCE23BIS028"] = "MITHRA N GOWDA";
    usnData["RVCE23BIS141"] = "MOHAMMAD OWEIS";
    usnData["RVCE23BIS125"] = "MOHAMMED HUZAIF S";
    usnData["RVCE23BIS092"] = "N SAI SHREYAS";
    usnData["RVCE23BIS006"] = "N VARUN";
    usnData["RVCE23BIS031"] = "NAVYA";
    usnData["RVCE23BIS069"] = "NIHAAL SONTELA PRAKASH";
    usnData["RVCE23BIS068"] = "NIVARTHI SRINIDHI KROUNCHA";
    usnData["RVCE23BIS019"] = "PALLAVI C";
    usnData["RVCE23BIS084"] = "PARTHAV PRATIM M";
    usnData["RVCE23BIS098"] = "PAVAN P S";
    usnData["RVCE23BIS055"] = "PEDDA NAGA BHAVYA SREE";
    usnData["RVCE23BIS072"] = "PRAFULL GUPTA";
    usnData["RVCE23BIS087"] = "PRAJWAL C S";
    usnData["RVCE23BIS144"] = "PRAJWAL T S";
    usnData["RVCE23BIS036"] = "PRANSHU JOSHI";
    usnData["RVCE23BIS090"] = "PRARTHANA HIMANSHU UPADHYAYA";
    usnData["RVCE23BIS138"] = "PRARTHANA R";
    usnData["RVCE23BIS130"] = "PRATHAM BADDUR";
    usnData["RVCE23BIS059"] = "PRATHAM NILANGE";
    usnData["RVCE23BIS094"] = "PREETHAM M R";
    usnData["RVCE23BIS129"] = "PRIYANKA T R";
    usnData["RVCE23BIS083"] = "PULKIT GUPTA";
    usnData["RVCE23BIS143"] = "PUNEETH KUMAR K M";
    usnData["RVCE23BIS134"] = "PUNYESH M";
    usnData["RVCE23BIS023"] = "R ABHI";
    usnData["RVCE23BIS106"] = "RAJATA M HEGDE";
    usnData["RVCE23BIS133"] = "ROHAN R GOWDA";
    usnData["RVCE23BIS115"] = "SADHU VENKATA HEMANTH SAI";
    usnData["RVCE23BIS046"] = "SAI ARUN KUMAR CHANDRASEKAR";
    usnData["RVCE23BIS013"] = "SAKETH BHARADWAJ ANUPINDI";
    usnData["RVCE23BIS112"] = "SAMARTH KOTHATHI NARAYAN";
    usnData["RVCE23BIS082"] = "SAMIYA HELAL";
    usnData["RVCE23BIS012"] = "SANIA JOSEPH";
    usnData["RVCE23BIS104"] = "SATHVIK HEGDE";
    usnData["RVCE23BIS123"] = "SATHWIK PAI";
    usnData["RVCE23BIS128"] = "SHANKAR PATEL K U";
    usnData["RVCE23BIS009"] = "SHASWAT KUMAR";
    usnData["RVCE23BIS021"] = "SHOHAM MOHAPATRA";
    usnData["RVCE23BIS091"] = "SHRINIDHI";
    usnData["RVCE23BIS140"] = "SHRINIVAS J ALALAGERI";
    usnData["RVCE23BIS089"] = "SMRUTHI S KADAGADKAI";
    usnData["RVCE23BIS007"] = "SPANDANA K N";
    usnData["RVCE23BIS088"] = "SPOORTHI NAYAK";
    usnData["RVCE23BIS063"] = "SREEHARSHA TALLAPALLI";
    usnData["RVCE23BIS109"] = "SREEKANTHA VENKATA RAM";
    usnData["RVCE23BIS035"] = "SRI VISHNU P V";
    usnData["RVCE23BIS096"] = "SRIKANTH R";
    usnData["RVCE23BIS011"] = "SUBHAN SARKAR";
    usnData["RVCE23BIS067"] = "SUHANI KHURANA";
    usnData["RVCE23BIS014"] = "SUMIKHA D PRASAD";
    usnData["RVCE23BIS120"] = "SUMITRA";
    usnData["RVCE23BIS124"] = "SURABHI S";
    usnData["RVCE23BIS108"] = "SURYA TEJA SUBRAMANYAM";
    usnData["RVCE23BIS137"] = "SWAMY B S";
    usnData["RVCE23BIS056"] = "SWAYAM PRAYASH PAL";
    usnData["RVCE23BIS048"] = "TANIKONDA SAI KARAN";
    usnData["RVCE23BIS126"] = "TANISHA SATRUJEET DEY";
    usnData["RVCE23BIS077"] = "TANMAY BAJPAI";
    usnData["RVCE23BIS142"] = "V NIKHIL";
    usnData["RVCE23BIS040"] = "VANI MITTAL";
    usnData["RVCE23BIS080"] = "VANSH BHARDWAJ";
    usnData["RVCE23BIS060"] = "VEDANT BATHWAL";
    usnData["RVCE23BIS027"] = "VIJESH";
    usnData["RVCE23BIS086"] = "VINAY SINNUR";
    usnData["RVCE23BIS117"] = "VINAYAK KUMAR SINGH";
    usnData["RVCE23BIS105"] = "VISHRUTH M DONIPARTHI";
    usnData["RVCE23BIS135"] = "YASHVANTH M U";
    usnData["RVCE23BIS001"] = "YASHWANTH RATHI";
    usnData["RVCE23BIS118"] = "YOGENDRA AJAY REDDY MAREDDY";
    usnData["RVCE23BIS062"] = "YUKTA ASHOK";
    usnData["RVCE21BIS011"] = "R KHOUSTHUB";
    usnData["RVCE23BAI068"] = "AADITEY CHALVA";
    usnData["RVCE23BAI016"] = "AANISH KHAN";
    usnData["RVCE23BAI100"] = "ABHAYACHANDRA C";
    usnData["RVCE23BAI113"] = "ABHILASH MAIYA Y";
    usnData["RVCE23BAI013"] = "ADHEESH MUDGAL";
    usnData["RVCE23BAI108"] = "ADITHYA ACHARYA U";
    usnData["RVCE23BAI043"] = "ADITYA KAUSHIK";
    usnData["RVCE23BAI051"] = "ADITYA RANJAN";
    usnData["RVCE23BAI097"] = "ADITYA TRIPATHI";
    usnData["RVCE23BAI035"] = "AFFAN YASIR";
    usnData["RVCE23BAI007"] = "AHIBHRUTH A";
    usnData["RVCE23BAI018"] = "ALROY DEON SALDANHA";
    usnData["RVCE23BAI028"] = "AMOGH A P";
    usnData["RVCE23BAI020"] = "AMUDHAN S";
    usnData["RVCE23BAI101"] = "ANAMAY MITTAL";
    usnData["RVCE23BAI008"] = "ANIKA VIDYA RAGHAV";
    usnData["RVCE23BAI064"] = "ANIKET R T";
    usnData["RVCE23BAI052"] = "ANJALI SURESH KALARIKKAL";
    usnData["RVCE23BAI033"] = "ANUPAMA";
    usnData["RVCE23BAI023"] = "APOORVA KRISHNA P";
    usnData["RVCE23BAI048"] = "ARINDAM GUPTA";
    usnData["RVCE23BAI104"] = "ASHISH R BIRADAR";
    usnData["RVCE23BAI081"] = "B VINAYAKA AILI";
    usnData["RVCE23BAI090"] = "BALLUPET PRAKASH MONAL";
    usnData["RVCE23BAI112"] = "BHAVIN BIJU";
    usnData["RVCE23BAI034"] = "BHEEMARAJ DODDAMANI";
    usnData["RVCE23BAI042"] = "BIRADAR ABHISHEK MALLIKARJUN";
    usnData["RVCE23BAI078"] = "DAKSH CHAUHAN";
    usnData["RVCE23BAI055"] = "DHAKSHA MUTHUKUMARAN";
    usnData["RVCE23BAI038"] = "DHANUSH K M";
    usnData["RVCE23BAI117"] = "DHANUSH R MOOLEMANE";
    usnData["RVCE23BAI096"] = "DHRUV PATANKAR";
    usnData["RVCE23BAI067"] = "DIPTANSHU KUMAR";
    usnData["RVCE23BAI054"] = "GARV AGARWALLA";
    usnData["RVCE23BAI029"] = "GNANENDRA NAIDU N";
    usnData["RVCE23BAI111"] = "HEMA UMESH HEGDE";
    usnData["RVCE23BAI118"] = "ISHAN SHEKHAR PRASAD";
    usnData["RVCE23BAI021"] = "ISHITA GOYAL";
    usnData["RVCE23BAI057"] = "JOSEPH REJO MATHEW";
    usnData["RVCE23BAI066"] = "JUNED BABA D HUNASHIMARAD";
    usnData["RVCE23BAI077"] = "K S SHAMITH RAJ";
    usnData["RVCE23BAI061"] = "KARNATI LAKSHMI SREE";
    usnData["RVCE23BAI019"] = "KASHISH GUPTA";
    usnData["RVCE23BAI060"] = "KAVYA JAIN";
    usnData["RVCE23BAI089"] = "KEERTHI V C";
    usnData["RVCE23BAI085"] = "KUMAR YASH";
    usnData["RVCE23BAI102"] = "KUSHAL S GOWDA";
    usnData["RVCE23BAI119"] = "MACHANI BHANU TEJA";
    usnData["RVCE23BAI004"] = "MAHESHKUMAR";
    usnData["RVCE23BAI003"] = "MANOJ";
    usnData["RVCE23BAI040"] = "MANVITH S";
    usnData["RVCE23BAI036"] = "MAYUR KUMAR K N";
    usnData["RVCE23BAI122"] = "MEDHA SANKETH";
    usnData["RVCE23BAI086"] = "MOHIT M";
    usnData["RVCE23BAI105"] = "MOHITH V";
    usnData["RVCE23BAI044"] = "MONIL PALAK MEHTA";
    usnData["RVCE23BAI072"] = "MOWIN S";
    usnData["RVCE23BAI127"] = "HARSH AGRAWAL";
    usnData["RVCE23BAI074"] = "MYLAVARAM PHANIKUMAR SAHASRA";
    usnData["RVCE23BAI002"] = "N MOHAMMED AKHIL";
    usnData["RVCE23BAI106"] = "N YAMINI";
    usnData["RVCE23BAI039"] = "NANDINI C";
    usnData["RVCE23BAI069"] = "NANDINI R ARAVINDAKSHAN";
    usnData["RVCE23BAI059"] = "NAVYASRI MAHITHA PULIPATI";
    usnData["RVCE23BAI005"] = "NEELAM J";
    usnData["RVCE23BAI115"] = "NIRANJAN S KAITHOTA";
    usnData["RVCE23BAI025"] = "NISHAN U SHETTY";
    usnData["RVCE23BAI027"] = "NISHTA N SHETTY";
    usnData["RVCE23BAI062"] = "NITISH AGARWAL";
    usnData["RVCE23BAI017"] = "NITYA SHARMA";
    usnData["RVCE23BAI056"] = "PENCHALA HIMASHREE PERUMALLA";
    usnData["RVCE23BAI099"] = "PRATHAM M MALLYA";
    usnData["RVCE23BAI120"] = "PREETAM BAHETI";
    usnData["RVCE23BAI006"] = "PREETHAM R";
    usnData["RVCE23BAI046"] = "PRIYANSH ABHISHEK PODDAR";
    usnData["RVCE23BAI058"] = "R DAKSHARANI";
    usnData["RVCE23BAI092"] = "RAGHAVI U BALER";
    usnData["RVCE23BAI103"] = "RAMITA K A";
    usnData["RVCE23BAI095"] = "RAVI KISHAN KUMAR";
    usnData["RVCE23BAI065"] = "RAYALA YUVARAJ VAISHNAV";
    usnData["RVCE23BAI047"] = "RUSHIL SHODAVARAM";
    usnData["RVCE23BAI087"] = "S VISHWANATHA";
    usnData["RVCE23BAI009"] = "SACHIT RAMESHA GOWDA";
    usnData["RVCE23BAI082"] = "SAMRUDDHI D";
    usnData["RVCE23BAI109"] = "SANKALP KHAMESRA";
    usnData["RVCE23BAI053"] = "SASANK SEKHAR PANDA";
    usnData["RVCE23BAI084"] = "SHALINI P";
    usnData["RVCE23BAI094"] = "SHANAVI NARAYAN";
    usnData["RVCE23BAI024"] = "SHANTHESH A S";
    usnData["RVCE23BAI049"] = "SHASHANK KRISHNAMANI";
    usnData["RVCE23BAI012"] = "SHAURYA SINGH";
    usnData["RVCE23BAI121"] = "SHRAVYAA S";
    usnData["RVCE23BAI041"] = "SHRESTA NAMBURI";
    usnData["RVCE23BAI076"] = "SHREYA MOHAN";
    usnData["RVCE23BAI107"] = "SHREYAS BHARADWAJ";
    usnData["RVCE23BAI073"] = "SHRIPOORNA BADAGANDI";
    usnData["RVCE23BAI015"] = "SHUBH SOMANI";
    usnData["RVCE23BAI075"] = "SHUBHADITYA BASUDEO BECHAN";
    usnData["RVCE23BAI123"] = "SHUBHAM KUMAR PANDEY";
    usnData["RVCE23BAI031"] = "SIDDARTH A THOTADA";
    usnData["RVCE23BAI032"] = "SIRI KUMAR C S";
    usnData["RVCE23BAI114"] = "SOURABH R SHETTY";
    usnData["RVCE23BAI088"] = "SREEHARISH T J";
    usnData["RVCE23BAI116"] = "SRI RAM A";
    usnData["RVCE23BAI079"] = "SRIHARI S";
    usnData["RVCE23BAI022"] = "SRUJAN R";
    usnData["RVCE23BAI125"] = "SUMITH S SHET";
    usnData["RVCE23BAI098"] = "SURAVI REDDY";
    usnData["RVCE23BAI071"] = "SURYA PRATAP SINGH";
    usnData["RVCE23BAI083"] = "T P MOHITH";
    usnData["RVCE23BAI080"] = "TANUJ S";
    usnData["RVCE23BAI045"] = "TEJAS ANAND";
    usnData["RVCE23BAI026"] = "THARUN GOWDA P R";
    usnData["RVCE23BAI093"] = "VAIBHAV S P";
    usnData["RVCE23BAI010"] = "VAIVASWAT VERMA";
    usnData["RVCE23BAI001"] = "VELUMURI SRIRAM KUMAR";
    usnData["RVCE23BAI110"] = "VIJAYKUMAR B K";
    usnData["RVCE23BAI050"] = "VIKAS LALWANI";
    usnData["RVCE23BAI091"] = "VINOD KUMAR";
    usnData["RVCE23BAI070"] = "YASH SHARMA";
    usnData["RVCE23BAI037"] = "YASHAS H D";
    usnData["RVCE23BAI014"] = "YASHNA BHANDARY";
    usnData["RVCE23BAI011"] = "YASHPREET GOYAL";
    usnData["RVCE23BAI063"] = "YUG SHIVHARE";
    usnData["RVCE23BAI030"] = "ZAID SHARIEFF";
    usnData["RVCE23BAI126"] = "MANYA SHARMA";
    usnData["RVCE23BBT056"] = "AJ DEEKSHA";
    usnData["RVCE23BBT018"] = "AABHA PARAG TEMBHURNE";
    usnData["RVCE23BBT044"] = "AARTI ANAND";
    usnData["RVCE23BBT004"] = "AARUSHI DAS";
    usnData["RVCE23BBT040"] = "ABHINAV SRINIVASAN";
    usnData["RVCE23BBT017"] = "ADIT NIKHIL MUTNALKAR";
    usnData["RVCE23BBT043"] = "ADITI DESAI";
    usnData["RVCE23BBT038"] = "ADITYA RAJ";
    usnData["RVCE23BBT054"] = "ADVAITH VENKATA RAMBHATLA";
    usnData["RVCE23BBT027"] = "ANANYA G";
    usnData["RVCE23BBT012"] = "ANANYA SREEKUMAR";
    usnData["RVCE23BBT023"] = "ANANYA SUDARSAN";
    usnData["RVCE23BBT045"] = "APOORVAM R";
    usnData["RVCE23BBT009"] = "ARATRIKA DAS";
    usnData["RVCE23BBT002"] = "ARCHISHA NAMBIAR";
    usnData["RVCE23BBT062"] = "ARYA TOTE";
    usnData["RVCE23BBT050"] = "BEERLING";
    usnData["RVCE23BBT035"] = "BHARGAVI S";
    usnData["RVCE23BBT063"] = "BHAVANA T G";
    usnData["RVCE23BBT057"] = "CHANDAN K S";
    usnData["RVCE23BBT007"] = "DHARSHINI K";
    usnData["RVCE23BBT029"] = "DHRUTHI";
    usnData["RVCE23BBT020"] = "DISHA V RAO";
    usnData["RVCE23BBT059"] = "G DAKSHA REDDY";
    usnData["RVCE23BBT006"] = "H M AMRUTHA SHARMA";
    usnData["RVCE23BBT013"] = "HAR SUDARSAN CHINTA";
    usnData["RVCE23BBT047"] = "HARSHITH KRISHNA K";
    usnData["RVCE23BBT011"] = "HARSHITHA SHRAVYA";
    usnData["RVCE23BBT032"] = "HEMASHREE G";
    usnData["RVCE23BBT049"] = "IRANNA GURULINGAPPA GUNNAPUR";
    usnData["RVCE23BBT030"] = "JAYALAKSHMI M";
    usnData["RVCE23BBT008"] = "KAAVYASHREE VINAYAGAMURTHY";
    usnData["RVCE23BBT003"] = "KANVA UDUPA";
    usnData["RVCE23BBT010"] = "LOUIS MATHEW";
    usnData["RVCE23BBT016"] = "MONIKA V";
    usnData["RVCE23BBT046"] = "N MAHESH";
    usnData["RVCE23BBT019"] = "N SIVAKHAMI";
    usnData["RVCE23BBT001"] = "NAVNI HEGDE";
    usnData["RVCE23BBT026"] = "NEHA N MADANGERIKAR";
    usnData["RVCE23BBT053"] = "NEYA YALLURKAR";
    usnData["RVCE23BBT014"] = "NITISHA GORAI";
    usnData["RVCE23BBT022"] = "NIVRITI JAIN";
    usnData["RVCE23BBT034"] = "PRAJAKTA PATIL";
    usnData["RVCE23BBT036"] = "PRIYAM PARASHAR";
    usnData["RVCE23BBT024"] = "PRUTHA V MURTHY";
    usnData["RVCE23BBT021"] = "R SRIVARDHAN";
    usnData["RVCE23BBT041"] = "RACHANA M";
    usnData["RVCE23BBT042"] = "RAHUL GOWDA S P";
    usnData["RVCE23BBT060"] = "SAHANA B";
    usnData["RVCE23BBT051"] = "SALVIKA SAHU";
    usnData["RVCE23BBT025"] = "SANJANA APPA KADPODKAR";
    usnData["RVCE23BBT028"] = "SHAARNGINI GALAGALI";
    usnData["RVCE23BBT061"] = "SHASHANK N";
    usnData["RVCE23BBT037"] = "SHIVAM KUMAR";
    usnData["RVCE23BBT033"] = "SHRAVANI B";
    usnData["RVCE23BBT039"] = "SHRIYA A MAIYA";
    usnData["RVCE23BBT015"] = "SRIJEETA GHOSH";
    usnData["RVCE23BBT048"] = "SYEDA NOOREEN FATHIMA";
    usnData["RVCE23BBT005"] = "TANYA PRASHANTH";
    usnData["RVCE23BBT055"] = "VARSHA G";
    usnData["RVCE23BBT052"] = "VIHASINI J";
    usnData["RVCE23BBT058"] = "VIJETHA S";
    usnData["RVCE23BBT031"] = "VINAYAKA DJ";
    usnData["RVCE23BCD055"] = "ADITYA A SHIDLING";
    usnData["RVCE23BCD025"] = "AADITYA KHURANA";
    usnData["RVCE23BCD051"] = "ADITYA BHANDARI";
    usnData["RVCE23BCD024"] = "ADITYA RUKMANGAD";
    usnData["RVCE23BCD012"] = "ADITYA SHAINESH";
    usnData["RVCE23BCD008"] = "AMRITESH SAHU";
    usnData["RVCE23BCD039"] = "AN KEERTHI SAAGAR";
    usnData["RVCE23BCD036"] = "ANANT AHLAWAT";
    usnData["RVCE23BCD006"] = "ANIKA KRISHNA";
    usnData["RVCE23BCD010"] = "ANUJ DEVPURA";
    usnData["RVCE23BCD034"] = "ANUSKA MISHRA";
    usnData["RVCE23BCD004"] = "APOORV KUMAR VERMA";
    usnData["RVCE23BCD040"] = "CHARAN N";
    usnData["RVCE23BCD038"] = "DHRUV DHANKHER";
    usnData["RVCE23BCD044"] = "G L SHRAVANI";
    usnData["RVCE23BCD002"] = "G M VAISHNAVI";
    usnData["RVCE23BCD046"] = "GANESH HANAMANTAPPA VEERAPUR";
    usnData["RVCE23BCD009"] = "GAYATHRI SUNIL NAMBIAR";
    usnData["RVCE23BCD054"] = "ISHANI SHETTY";
    usnData["RVCE23BCD026"] = "JAI SINHA";
    usnData["RVCE23BCD013"] = "JANANI S";
    usnData["RVCE23BCD029"] = "KAUSHIK DAS";
    usnData["RVCE23BCD001"] = "KAUSHIK RAYADURGA";
    usnData["RVCE23BCD022"] = "KHUSHI GAONKAR";
    usnData["RVCE23BCD037"] = "KUSHAL SRIVASTAVA";
    usnData["RVCE23BCD018"] = "LIKITH K G";
    usnData["RVCE23BCD028"] = "MALLELA NITEESH SAI KUMAR";
    usnData["RVCE23BCD021"] = "MANAN JOSHI";
    usnData["RVCE23BCD041"] = "MUHAMMAD UMAR YAKSAMBI";
    usnData["RVCE23BCD003"] = "MRIDA PRADHAN";
    usnData["RVCE23BCD045"] = "NIKITA";
    usnData["RVCE23BCD053"] = "NITIN BHASKAR";
    usnData["RVCE23BCD035"] = "NOEL SHAJ MATHEW";
    usnData["RVCE23BCD019"] = "OSHI KHABYA";
    usnData["RVCE23BCD052"] = "PARTHA SURESH";
    usnData["RVCE23BCD050"] = "POORVI BELLUR";
    usnData["RVCE23BCD023"] = "PRABAL KUMAR SHUKLA";
    usnData["RVCE23BCD030"] = "PRAVALIKA NAGAPPAGARI";
    usnData["RVCE23BCD057"] = "RAGHAV N";
    usnData["RVCE23BCD011"] = "RAHUL PATNAIK";
    usnData["RVCE23BCD007"] = "ROHAN JONATHAN ANILAL";
    usnData["RVCE23BCD048"] = "ROHAN NITHIN RAO";
    usnData["RVCE23BCD005"] = "RUTIKAA M";
    usnData["RVCE23BCD061"] = "SADASHIV S TODAKAR";
    usnData["RVCE23BCD042"] = "SAMARTHA K B";
    usnData["RVCE23BCD047"] = "SANVI H S";
    usnData["RVCE23BCD032"] = "SHAILEE TEJAS SHAH";
    usnData["RVCE23BCD049"] = "SHARANYA RAO YARAGUDIPATI";
    usnData["RVCE23BCD033"] = "SHASHANK REDDY REDDIMALLA";
    usnData["RVCE23BCD031"] = "SHREYA RAVI";
    usnData["RVCE23BCD015"] = "SHREYASH BHASKAR PATIL";
    usnData["RVCE23BCD027"] = "SHREYASH PARASAR";
    usnData["RVCE23BCD056"] = "SHRIPAD G MARADI";
    usnData["RVCE23BCD016"] = "SINCHANA R V";
    usnData["RVCE23BCD059"] = "SPOORTHY S";
    usnData["RVCE23BCD017"] = "SYEDA FATHIMA ZAHARA";
    usnData["RVCE23BCD043"] = "VENKATESHA B V";
    usnData["RVCE23BCD060"] = "VISHAL P JOY";
    usnData["RVCE23BCD058"] = "VISHAL S";
    usnData["RVCE23BCD062"] = "YASHASHWINIS";
    usnData["RVCE23BCD014"] = "YASHASWINI H S";
    usnData["RVCE23BCD063"] = "YOGESH R SINDAGI";
    usnData["RVCE23BCD064"] = "BHUVANESH BEHERA";
    usnData["RVCE23BCS052"] = "A NISCHAL ABHYUDH REDDY";
    usnData["RVCE23BCS042"] = "AADIRA SHIVAKUMAR";
    usnData["RVCE23BCS039"] = "AAKARSH PRABHU";
    usnData["RVCE23BCS025"] = "AAYUSHH KP NAIK";
    usnData["RVCE23BCS178"] = "ABHAYS S";
    usnData["RVCE23BCS249"] = "ABHIJAT BHAT";
    usnData["RVCE23BCS008"] = "ABHINAV KRISHNA RAYACHOTI";
    usnData["RVCE23BCS048"] = "ABHINAV YOGISH";
    usnData["RVCE23BCS262"] = "ABHISHEK VARMA";
    usnData["RVCE23BCS057"] = "ABHISIKTA MAITRA";
    usnData["RVCE23BCS224"] = "ABHYUDAY SHARMA";
    usnData["RVCE23BCS111"] = "ACKSHAYA KEERTHI G";
    usnData["RVCE23BCS135"] = "ADHYAS NIRANJAN";
    usnData["RVCE23BCS151"] = "ADITI R";
    usnData["RVCE23BCS247"] = "ADITYA KUMAR";
    usnData["RVCE23BCS219"] = "ADITYA MENIA";
    usnData["RVCE23BCS079"] = "ADITYA NARAYAN";
    usnData["RVCE23BCS071"] = "ADITYA SAHAY";
    usnData["RVCE23BCS195"] = "AISHWARYA V SHETTY";
    usnData["RVCE23BCS198"] = "AJITH KOLI";
    usnData["RVCE23BCS223"] = "AKASH SIVAPRASATH";
    usnData["RVCE23BCS213"] = "AKHIL JOSE";
    usnData["RVCE23BCS238"] = "AKSHAT ARYA";
    usnData["RVCE23BCS212"] = "AKSHAT GUPTA";
    usnData["RVCE23BCS144"] = "AKSHATHA N";
    usnData["RVCE23BCS107"] = "AKSHITH DESU";
    usnData["RVCE23BCS116"] = "AMAN R";
    usnData["RVCE23BCS264"] = "AMARJEETH HS";
    usnData["RVCE23BCS145"] = "AMOL VYAS";
    usnData["RVCE23BCS164"] = "ANAND JUNJHARAWAD";
    usnData["RVCE23BCS226"] = "ANANYA SHASHIDHAR HEBBAR";
    usnData["RVCE23BCS216"] = "ANGADPREET SINGH";
    usnData["RVCE23BCS214"] = "ANIMESH SAPRA";
    usnData["RVCE23BCS009"] = "ANIRUDDH SHREYAS";
    usnData["RVCE23BCS203"] = "ANIRUDH KULKARNI";
    usnData["RVCE23BCS222"] = "ANISH";
    usnData["RVCE23BCS020"] = "ANSH RAVI KASHYAP";
    usnData["RVCE23BCS275"] = "ANSHIKA PRASHANTH";
    usnData["RVCE23BCS246"] = "ANSUMAN RATH";
    usnData["RVCE23BCS060"] = "ANURAG SATAPATHY";
    usnData["RVCE23BCS305"] = "ANUSHRUTH VEERAMALLA";
    usnData["RVCE23BCS284"] = "ARCHANA";
    usnData["RVCE23BCS100"] = "ARHAM JAMIL";
    usnData["RVCE23BCS227"] = "ARPITA";
    usnData["RVCE23BCS024"] = "ARUSHI VAIDYA";
    usnData["RVCE23BCS069"] = "ARYAN GUPTA";
    usnData["RVCE23BCS209"] = "ARYAN RAI";
    usnData["RVCE23BCS248"] = "ARYMAN CHAUDHARY";
    usnData["RVCE23BCS096"] = "ASHMIT MISHRA";
    usnData["RVCE23BCS091"] = "ASHWIN NAGENDRA BHAT";
    usnData["RVCE23BCS235"] = "ASTITWA TANMAY";
    usnData["RVCE23BCS131"] = "AVANISH KANNAN";
    usnData["RVCE23BCS027"] = "AVYAY BHAT";
    usnData["RVCE23BCS292"] = "AYUSH AMAN";
    usnData["RVCE23BCS119"] = "B HANUMANTH";
    usnData["RVCE23BCS143"] = "B M MANOHARA";
    usnData["RVCE23BCS299"] = "BHARATH D";
    usnData["RVCE23BCS197"] = "BHAVAN TIMMAPPA GOND";
    usnData["RVCE23BCS077"] = "BHAVIKA BANDU";
    usnData["RVCE23BCS170"] = "BHAVIN BHAT";
    usnData["RVCE23BCS086"] = "BHOOMIKA SUNDAR";
    usnData["RVCE23BCS092"] = "BONAGIRI RAMA KRISHNA VIVEK";
    usnData["RVCE23BCS298"] = "BRAJESH PAIP N";
    usnData["RVCE23BCS200"] = "CHAITHANYA B";
    usnData["RVCE23BCS128"] = "CHAITHANYA SHADAKSHARI";
    usnData["RVCE23BCS207"] = "CHANDAN G";
    usnData["RVCE23BCS204"] = "CHANDANA M N";
    usnData["RVCE23BCS215"] = "CHETAN M PATIL";
    usnData["RVCE23BCS029"] = "CHHAVI PAREEK";
    usnData["RVCE23BCS072"] = "CHIRAG A CHINTAAL";
    usnData["RVCE23BCS201"] = "CHIRAG SANDESH SHETTY";
    usnData["RVCE23BCS055"] = "CHIRANTHAN K";
    usnData["RVCE23BCS049"] = "CHITKALA PATIL";
    usnData["RVCE23BCS172"] = "D DIVYASHREE";
    usnData["RVCE23BCS252"] = "D RAKSHITHA";
    usnData["RVCE23BCS161"] = "DAIVIK SHENOY";
    usnData["RVCE23BCS160"] = "DARSHAN CHAVAN";
    usnData["RVCE23BCS098"] = "DHANGAR RAJU THAYAPPA";
    usnData["RVCE23BCS181"] = "DILSHAD AHMED";
    usnData["RVCE23BCS202"] = "DISHANTH A M";
    usnData["RVCE23BCS124"] = "ESHANYE J";
    usnData["RVCE23BCS267"] = "ESHITHA CHOWDARY NATTEM";
    usnData["RVCE23BCS297"] = "ESHWAR M";
    usnData["RVCE23BCS182"] = "G C NIKHIL";
    usnData["RVCE23BCS054"] = "GAGAN B C";
    usnData["RVCE23BCS037"] = "GARVIT CHOUDHARY";
    usnData["RVCE23BCS043"] = "GORLA RAHUL REDDY";
    usnData["RVCE23BCS121"] = "GREESHMAS";
    usnData["RVCE23BCS089"] = "GUJAR ADVAY KIRAN";
    usnData["RVCE23BCS239"] = "HARSH PATEL";
    usnData["RVCE23BCS165"] = "HARSHIT RAJ";
    usnData["RVCE23BCS241"] = "HARSHIT VARMA";
    usnData["RVCE23BCS158"] = "HARSHITH KUMAR S B";
    usnData["RVCE23BCS001"] = "HEMANG SHRIKAR DESAI";
    usnData["RVCE23BCS220"] = "HITARTH MEHRA";
    usnData["RVCE23BCS010"] = "IAN JEM";
    usnData["RVCE23BCS156"] = "ISHAAN C";
    usnData["RVCE23BCS040"] = "ISHAN KUMAR";
    usnData["RVCE23BCS013"] = "ISHITHA BUSETTY";
    usnData["RVCE23BCS191"] = "JESTAKUMAR";
    usnData["RVCE23BCS109"] = "JETTI KAMALA";
    usnData["RVCE23BCS104"] = "K MRUDULA REDDY";
    usnData["RVCE23BCS272"] = "K SRUJAN";
    usnData["RVCE23BCS147"] = "KALIANPUR ROHITH";
    usnData["RVCE23BCS217"] = "KAUSSHAL RAVIKUMAAR";
    usnData["RVCE23BCS110"] = "KAVYASHREE B K";
    usnData["RVCE23BCS123"] = "KIRAN KUMAR S";
    usnData["RVCE23BCS066"] = "KISHORE K";
    usnData["RVCE23BCS242"] = "KRISHANG REDDY";
    usnData["RVCE23BCS154"] = "KRUTHIKA N";
    usnData["RVCE23BCS067"] = "KSHITIJ C";
    usnData["RVCE23BCS188"] = "KUSHAL GOWDA C";
    usnData["RVCE23BCS117"] = "LAKSHMI S D";
    usnData["RVCE23BCS237"] = "LAKSHYA SHARMA";
    usnData["RVCE23BCS011"] = "LOCHAN NS";
    usnData["RVCE23BCS018"] = "M L VARSHITHA";
    usnData["RVCE23BCS184"] = "M P PREETHAM";
    usnData["RVCE23BCS051"] = "MR NITHISH";
    usnData["RVCE23BCS253"] = "MAADHURYA KEFTA";
    usnData["RVCE23BCS287"] = "MADHUMEETA OMPRAKASH";
    usnData["RVCE23BCS293"] = "MANAN RAJWANSHI";
    usnData["RVCE23BCS133"] = "MANISH H PARASHAR";
    usnData["RVCE23BCS118"] = "MANISH TANDURKAR";
    usnData["RVCE23BCS136"] = "MANJUNATH NAYAKA B P";
    usnData["RVCE23BCS279"] = "MANOJ S";
    usnData["RVCE23BCS006"] = "MANUS AGARWAL";
    usnData["RVCE23BCS258"] = "MANYA Y";
    usnData["RVCE23BCS012"] = "MANYAMALA SUNAINA";
    usnData["RVCE23BCS265"] = "MEGHANA D HEGDE";
    usnData["RVCE23BCS233"] = "MOHAMMAD ABESS ZAIDII";
    usnData["RVCE23BCS126"] = "MOHAMMAD DANISH Z B";
    usnData["RVCE23BCS286"] = "MOHAN KARTIK";
    usnData["RVCE23BCS087"] = "MONAL RAI";
    usnData["RVCE23BCS186"] = "MONISHA A";
    usnData["RVCE23BCS290"] = "MONISHA R";
    usnData["RVCE23BCS058"] = "MOUMI BASU";
    usnData["RVCE23BCS169"] = "N JEEVAN REDDY";
    usnData["RVCE23BCS251"] = "NS SAMYAK VARMA";
    usnData["RVCE23BCS045"] = "NAIDU YUVATEJA";
    usnData["RVCE23BCS244"] = "NAMITA HIREMATH";
    usnData["RVCE23BCS094"] = "NAMRATA SRINIVASA";
    usnData["RVCE23BCS120"] = "NAVAMI LOKESH";
    usnData["RVCE23BCS208"] = "NAVYA MADIRAJU";
    usnData["RVCE23BCS080"] = "NAYANA JAGADISH RAIKAR";
    usnData["RVCE23BCS289"] = "NEERAJ GOWDA M";
    usnData["RVCE23BCS034"] = "NIDHI VINAYAK KULKARNI";
    usnData["RVCE23BCS102"] = "NIHAL SONI";
    usnData["RVCE23BCS228"] = "NIKHIL N BHARADWAJ";
    usnData["RVCE23BCS168"] = "NIKHIL PARASHURAM BAKALE";
    usnData["RVCE23BCS300"] = "NIKITA S RAJ KAPINI";
    usnData["RVCE23BCS278"] = "NIRANJANA R N";
    usnData["RVCE23BCS174"] = "NISCHAL R E";
    usnData["RVCE23BCS245"] = "NISKA SACHIN";
    usnData["RVCE23BCS095"] = "NITHYA J";
    usnData["RVCE23BCS028"] = "NITHYASREE SUBRAMANIAN";
    usnData["RVCE23BCS155"] = "NITYA P MOHARE";
    usnData["RVCE23BCS256"] = "P KOTI DARSHAN";
    usnData["RVCE23BCS050"] = "PANEESH Y GOWDA";
    usnData["RVCE23BCS250"] = "PARTH";
    usnData["RVCE23BCS288"] = "PARTH AJAY RATHI";
    usnData["RVCE23BCS254"] = "PAVAN V";
    usnData["RVCE23BCS103"] = "PIYUSH KHERIA";
    usnData["RVCE23BCS075"] = "POORVI DURDI";
    usnData["RVCE23BCS266"] = "POTURI ANIRUDH SAI";
    usnData["RVCE23BCS295"] = "PRABHANJAN S BABU";
    usnData["RVCE23BCS173"] = "PRAJWAL N";
    usnData["RVCE23BCS146"] = "PRAJWAL ROODAGI";
    usnData["RVCE23BCS090"] = "PRAJWALT A";
    usnData["RVCE23BCS210"] = "PRAKHAR PARASHAR";
    usnData["RVCE23BCS041"] = "PRAKHYA RAJ";
    usnData["RVCE23BCS268"] = "PRANAV P SANJEE";
    usnData["RVCE23BCS021"] = "PRANAV VENKATESH JAMBUR";
    usnData["RVCE23BCS082"] = "PRARTHANA PRADEEPKUMAR KULKARNI";
    usnData["RVCE23BCS065"] = "PRASASTHI SANJANA CHEKURI";
    usnData["RVCE23BCS022"] = "PRATEEK S D";
    usnData["RVCE23BCS099"] = "PRATHIKSHA R";
    usnData["RVCE23BCS023"] = "PRATYUSH RAMESH BIDARE";
    usnData["RVCE23BCS175"] = "PREETHAM CHANDRA B YADAGERE";
    usnData["RVCE23BCS221"] = "PREYANSH PANDA";
    usnData["RVCE23BCS047"] = "PRIYANSHI SINGHI";
    usnData["RVCE23BCS281"] = "PUNEETH R";
    usnData["RVCE23BCS122"] = "R AKASH KUMAR";
    usnData["RVCE23BCS074"] = "R JEFFREY MARIARAJ";
    usnData["RVCE23BCS017"] = "RAGHAVENDRA PRASAD B M";
    usnData["RVCE23BCS193"] = "RAHUL LAXMAN RATHOD";
    usnData["RVCE23BCS271"] = "RAHUL N M";
    usnData["RVCE23BCS083"] = "RAHUL RAJESH RAIKAR";
    usnData["RVCE23BCS005"] = "RAJAT GA";
    usnData["RVCE23BCS194"] = "RAJKIRAN T";
    usnData["RVCE23BCS291"] = "RAJUGOWDA PATIL";
    usnData["RVCE23BCS159"] = "RISHI P";
    usnData["RVCE23BCS211"] = "RISHIT BIST";
    usnData["RVCE23BCS097"] = "RITHEK JAGADESH CHANDRAN POORANI";
    usnData["RVCE23BCS062"] = "RITHYU R";
    usnData["RVCE23BCS125"] = "ROHAN R GENNUR";
    usnData["RVCE23BCS269"] = "RUDRESH MS";
    usnData["RVCE23BCS263"] = "RUSHI SAHAN KURALLA";
    usnData["RVCE23BCS014"] = "RUSHIL T";
    usnData["RVCE23BCS134"] = "RUTVIK HEGDE";
    usnData["RVCE23BCS139"] = "S HARSHITHA";
    usnData["RVCE23BCS218"] = "SAARTHI BHATIA";
    usnData["RVCE23BCS171"] = "SAATHWIKA";
    usnData["RVCE23BCS255"] = "SACHETAN SHIVAPUTRA INCHAL";
    usnData["RVCE23BCS270"] = "SADHANA S H";
    usnData["RVCE23BCS185"] = "SAGAR TH";
    usnData["RVCE23BCS302"] = "SAI ABHIRAM M";
    usnData["RVCE23BCS148"] = "SAI LIKITH REDDY V";
    usnData["RVCE23BCS257"] = "SAKET MARATHE";
    usnData["RVCE23BCS282"] = "SAKSHI A S";
    usnData["RVCE23BCS276"] = "SALMAN ZAHEER ABDI";
    usnData["RVCE23BCS176"] = "SAMARTH R BANNI";
    usnData["RVCE23BCS019"] = "SAMPADA G KULKARNI";
    usnData["RVCE23BCS167"] = "SAMYAK RAO";
    usnData["RVCE23BCS064"] = "SARTH SASHAMA";
    usnData["RVCE23BCS044"] = "SATHVIK VASUDEVA";
    usnData["RVCE23BCS093"] = "SATVIK SHYAM";
    usnData["RVCE23BCS003"] = "SHARANYA D";
    usnData["RVCE23BCS280"] = "SHARANYA MADHYASTHA";
    usnData["RVCE23BCS261"] = "SHARANYA NARENDRAN";
    usnData["RVCE23BCS206"] = "SHASHANKA JOIS";
    usnData["RVCE23BCS306"] = "SHEPALI RANJAN";
    usnData["RVCE23BCS180"] = "SHREERAM GAJANAN PATGAR";
    usnData["RVCE23BCS130"] = "SHREYA PRASAD";
    usnData["RVCE23BCS192"] = "SHREYAS R GOWDA";
    usnData["RVCE23BCS187"] = "SHREYAS S";
    usnData["RVCE23BCS177"] = "SHRIKANT";
    usnData["RVCE23BCS068"] = "SHRINIVAS DESHPANDE";
    usnData["RVCE23BCS105"] = "SIDDHARTH RAJENDRAN";
    usnData["RVCE23BCS285"] = "SIDDU P JADHAV";
    usnData["RVCE23BCS152"] = "SIRI YASHA DINESH";
    usnData["RVCE23BCS088"] = "SIVAPURAM POOJA AMRUTHA";
    usnData["RVCE23BCS225"] = "SIYA P KURANDWAD";
    usnData["RVCE23BCS106"] = "SOMIN NARAIN";
    usnData["RVCE23BCS296"] = "SOUMYA";
    usnData["RVCE23BCS179"] = "SPANDANA M RAIKAR";
    usnData["RVCE23BCS153"] = "SPOORTHI RAVI PRATAP";
    usnData["RVCE23BCS127"] = "SRIKAR RAO H M";
    usnData["RVCE23BCS199"] = "SRINIDHI H";
    usnData["RVCE23BCS205"] = "SUBRAMANI M";
    usnData["RVCE23BCS149"] = "SUCHETHAN R";
    usnData["RVCE23BCS232"] = "SUHAS RAVI SHANKAR";
    usnData["RVCE23BCS026"] = "SUMADHVA KRISHNA H M";
    usnData["RVCE23BCS056"] = "SUMANA CHODAVARAPU";
    usnData["RVCE23BCS036"] = "SUMEDH UDUPA UPPINKUDRU";
    usnData["RVCE23BCS162"] = "SUMUKH S RAIKAR";
    usnData["RVCE23BCS303"] = "SUPREETH S";
    usnData["RVCE23BCS113"] = "SUPRITH G B";
    usnData["RVCE23BCS085"] = "SURABHI R";
    usnData["RVCE23BCS112"] = "SURAJ SREEDHARA";
    usnData["RVCE23BCS129"] = "SURYA NARAYAN M";
    usnData["RVCE23BCS301"] = "SURYA PRAKASH GARLAPATI";
    usnData["RVCE23BCS016"] = "SUSHANTH JOSHI";
    usnData["RVCE23BCS304"] = "SUSHRUT RAGHUVEER NAYAK";
    usnData["RVCE23BCS150"] = "SYED AFTAB AHMED MADNI";
    usnData["RVCE23BCS137"] = "SYED MUZAMMIL HUSSAINI";
    usnData["RVCE23BCS166"] = "TAKSH DHAR";
    usnData["RVCE23BCS059"] = "TALLAM SRI SAI SUBRAMANYAM";
    usnData["RVCE23BCS138"] = "TALUR YASHWANTH";
    usnData["RVCE23BCS230"] = "TANEESHA S M";
    usnData["RVCE23BCS031"] = "TANISHA SRIVASTAVA";
    usnData["RVCE23BCS183"] = "TANMAY DEV D";
    usnData["RVCE23BCS070"] = "TANMAY VINAYAK";
    usnData["RVCE23BCS260"] = "TARUN R";
    usnData["RVCE23BCS140"] = "TEJASVI VASANT HEGDE";
    usnData["RVCE23BCS142"] = "THARUNKRISHNA M";
    usnData["RVCE23BCS053"] = "TRISHA BHATTACHARYA";
    usnData["RVCE23BCS101"] = "U SRUJANA REDDY";
    usnData["RVCE23BCS081"] = "V S SREENIVAAS";
    usnData["RVCE23BCS108"] = "VAANYA SINGH";
    usnData["RVCE23BCS157"] = "VAIBHAV P RODDAPPANAVAR";
    usnData["RVCE23BCS061"] = "VARUN DHANDHARIA";
    usnData["RVCE23BCS063"] = "VARUN G";
    usnData["RVCE23BCS141"] = "VARUN GOWDA R";
    usnData["RVCE23BCS240"] = "VED RAMESH";
    usnData["RVCE23BCS196"] = "VEDAKSHA M";
    usnData["RVCE23BCS294"] = "VIHAN RAJWANSHI";
    usnData["RVCE23BCS189"] = "VIKAS";
    usnData["RVCE23BCS277"] = "VIKAS K T";
    usnData["RVCE23BCS273"] = "VIKAS VIJAY MUDDANNANAVAR";
    usnData["RVCE23BCS035"] = "VINEETH RAO";
    usnData["RVCE23BCS274"] = "VINOD R";
    usnData["RVCE23BCS283"] = "VIPUL RAVIKUMAR";
    usnData["RVCE23BCS190"] = "VISHAL K BHAT";
    usnData["RVCE23BCS078"] = "VISHAL REDDY";
    usnData["RVCE23BCS046"] = "VISHWAS V";
    usnData["RVCE23BCS243"] = "VRUSHANK L M";
    usnData["RVCE23BCS076"] = "YADAMREDDY NAVANEETH";
    usnData["RVCE23BCS229"] = "YANDAPALLI TULYA REDDY";
    usnData["RVCE23BCS084"] = "YASH SARAOGI";
    usnData["RVCE23BCS259"] = "YASHASWINI K C";
    usnData["RVCE23BCS132"] = "YESHAS RAJU";
    usnData["RVCE23BCS002"] = "YUG JAIN";
    usnData["RVCE23BCS004"] = "YUVAT";
    usnData["RVCE23BCS163"] = "ZEENAT KHAN";
    usnData["RVCE23BCS307"] = "ARYAKI";
    usnData["RVCE23BCS308"] = "ADITYA S JAIN";
    usnData["RVCE23BCS309"] = "ADHITHI C IYER";
    usnData["RVCE23BCS310"] = "SHRIYAM ADYA SHARMA";
    usnData["RVCE23BCS312"] = "CHAHAK SRIVASTAVA";
    usnData["RVCE23BCS311"] = "A MITHRA";
    usnData["RVCE23BCS313"] = "SHREYAS G";
    usnData["RVCE23BCY020"] = "AADITYA RAJ";
    usnData["RVCE23BCY058"] = "AAMIR IBRAHIM";
    usnData["RVCE23BCY028"] = "AARNAV KEMBHAVI";
    usnData["RVCE23BCY060"] = "ABHINAV L G";
    usnData["RVCE23BCY009"] = "ADYA ANANYA";
    usnData["RVCE23BCY005"] = "AKSHAYA SANNAPU REDDY";
    usnData["RVCE23BCY030"] = "AMITANSH GUPTA";
    usnData["RVCE23BCY012"] = "AMULYA C";
    usnData["RVCE23BCY044"] = "AMULYA VINATHI MALIPATIL";
    usnData["RVCE23BCY024"] = "ANISH AGRAWAL";
    usnData["RVCE23BCY036"] = "ANKIT REDDY";
    usnData["RVCE23BCY033"] = "ATUL KUMAR MISHRA";
    usnData["RVCE23BCY048"] = "AVINASH ANISH";
    usnData["RVCE23BCY050"] = "CHARAN GOWDA K";
    usnData["RVCE23BCY055"] = "CHETHOHAAR J M";
    usnData["RVCE23BCY046"] = "DENISH DEKA";
    usnData["RVCE23BCY017"] = "DHRITI P ARYA";
    usnData["RVCE23BCY026"] = "ESHA SHARMA";
    usnData["RVCE23BCY018"] = "GOVARDHAN DHARMENDRA HEGDE";
    usnData["RVCE23BCY043"] = "HARON KHADAR";
    usnData["RVCE23BCY004"] = "HARSH SAGAR";
    usnData["RVCE23BCY016"] = "HARSHAVARDHAN N";
    usnData["RVCE23BCY008"] = "HIMANSHU SUHAG";
    usnData["RVCE23BCY022"] = "KAVYA";
    usnData["RVCE23BCY011"] = "KOUSHIK NAYAKA U";
    usnData["RVCE23BCY007"] = "MAYUR KIRAN KUMAR S";
    usnData["RVCE23BCY023"] = "MEDA MOUNIKA";
    usnData["RVCE23BCY013"] = "MITHUN";
    usnData["RVCE23BCY049"] = "MOHAMMED ABDUL RAZZAQ";
    usnData["RVCE23BCY052"] = "MOHANPRASAD";
    usnData["RVCE23BCY040"] = "MOHIT KUMAR SAHOO";
    usnData["RVCE23BCY047"] = "MOHITH D";
    usnData["RVCE23BCY037"] = "NIKHIL V P";
    usnData["RVCE23BCY056"] = "NIKITHA RODRIGUES";
    usnData["RVCE23BCY041"] = "NITHISH B";
    usnData["RVCE23BCY051"] = "NITIN D";
    usnData["RVCE23BCY038"] = "NUTHAN B";
    usnData["RVCE23BCY006"] = "OM ADITYA MISHRA";
    usnData["RVCE23BCY002"] = "PALLAVI O";
    usnData["RVCE23BCY039"] = "RUPA SHREE S";
    usnData["RVCE23BCY031"] = "SAANVI CHAUHAN";
    usnData["RVCE23BCY059"] = "SAHANA MARKANDE";
    usnData["RVCE23BCY061"] = "SAHARSHA";
    usnData["RVCE23BCY025"] = "SAKSHAM GUPTA";
    usnData["RVCE23BCY015"] = "SANJAY S";
    usnData["RVCE23BCY029"] = "SARTHAK LAKHOTIA";
    usnData["RVCE23BCY053"] = "SHREYA SRIVASTAVA";
    usnData["RVCE23BCY001"] = "SHRISH VASUDEVRAO DESHPANDE";
    usnData["RVCE23BCY019"] = "SNEHA PATEL";
    usnData["RVCE23BCY057"] = "SRIDULA O S";
    usnData["RVCE23BCY032"] = "SUNEESH BARE";
    usnData["RVCE23BCY014"] = "SUSHANTH N T";
    usnData["RVCE23BCY021"] = "TANISHK VIRAJ BHANAGE";
    usnData["RVCE23BCY003"] = "THUSHITHA R";
    usnData["RVCE23BCY035"] = "VIANCA CHOUDHARY";
    usnData["RVCE23BCY045"] = "VINAY";
    usnData["RVCE23BCY034"] = "WANGCHEN TRINLEY TOBGYAL";
    usnData["RVCE23BCY062"] = "YASH GAUTAM";
    usnData["RVCE23BCY054"] = "YASHAS M N";
    usnData["RVCE23BCY027"] = "YASHMITHA DESAI";
    usnData["RVCE23BCY063"] = "MUKESH T K M";
    usnData["RVCE23BCY064"] = "MIHIR SHRINIWAS ARYA";
    usnData["RVCE23BCY065"] = "ANANMAY ABHISHEK LOHIA";
    usnData["RVCE23BAS062"] = "ADITHI B V RAO";
    usnData["RVCE23BAS011"] = "ADITYA KARTHIK";
    usnData["RVCE23BAS021"] = "AJITH P N";
    usnData["RVCE23BAS040"] = "AKULA UDAY KIRAN";
    usnData["RVCE23BAS055"] = "AMAR HACHCHOLLI";
    usnData["RVCE23BAS033"] = "AMRUTHA PATARY";
    usnData["RVCE23BAS035"] = "ANANYA HEBBAR";
    usnData["RVCE23BAS045"] = "ANNIE EVANGELINE K";
    usnData["RVCE23BAS023"] = "ARYAN ACHARYA";
    usnData["RVCE23BAS043"] = "ATHARV MAHAJAN";
    usnData["RVCE23BAS004"] = "BHUVAN AGRAJ PASAM";
    usnData["RVCE23BAS042"] = "D S SARAYU SHREE";
    usnData["RVCE23BAS020"] = "DARSHAN ARJUN IBRAHIMPUR";
    usnData["RVCE23BAS046"] = "DUGAD RUTUJ MANOJ";
    usnData["RVCE23BAS051"] = "HANAMANT PUNDALIK HALATTI";
    usnData["RVCE23BAS058"] = "INDUSHREE G";
    usnData["RVCE23BAS059"] = "JAYATHI R";
    usnData["RVCE23BAS053"] = "KAVITHA S";
    usnData["RVCE23BAS031"] = "KHUSHI CHOUDKI";
    usnData["RVCE23BAS026"] = "KIRAN V AIRANI";
    usnData["RVCE23BAS003"] = "L NIDHI";
    usnData["RVCE23BAS028"] = "LAXMISAGAR PANDAPPA JANAMATTI";
    usnData["RVCE23BAS018"] = "LIKHIT ANANTHARAMA NAYAKA";
    usnData["RVCE23BAS044"] = "MAANYA G";
    usnData["RVCE23BAS060"] = "MANODNYA KORISHETTY";
    usnData["RVCE23BAS049"] = "MEHABOOB BASHA B";
    usnData["RVCE23BAS034"] = "MISBAH MOUMINAH";
    usnData["RVCE23BAS013"] = "MITHAKSHAR DJ";
    usnData["RVCE23BAS041"] = "MOHAMMED AFFAN";
    usnData["RVCE23BAS016"] = "MOVVA SAI LALITHADEVI";
    usnData["RVCE23BAS025"] = "NEELAGAR CHARAN";
    usnData["RVCE23BAS032"] = "NIDHI NAGAVI";
    usnData["RVCE23BAS061"] = "NIKHIL PRABHAKAR";
    usnData["RVCE23BAS001"] = "NIKHITA M";
    usnData["RVCE23BAS007"] = "NITESH S";
    usnData["RVCE23BAS024"] = "OM PATIL";
    usnData["RVCE23BAS017"] = "PAVITHRA M MAJJAGI";
    usnData["RVCE23BAS009"] = "POOVAIAH GN";
    usnData["RVCE23BAS047"] = "PRAKASH S";
    usnData["RVCE23BAS012"] = "PRANATHI S";
    usnData["RVCE23BAS005"] = "PRATHIKSHA G POOJARY";
    usnData["RVCE23BAS052"] = "PRATIKSHA MADIWALAYYA GADDIGIMATH";
    usnData["RVCE23BAS027"] = "PRIYANKA JOSELYN LOBO";
    usnData["RVCE23BAS039"] = "RACHIT MITTAL";
    usnData["RVCE23BAS064"] = "RAJDEEP SINGH NAGI";
    usnData["RVCE23BAS050"] = "RODHAM NIKITA SHARATH";
    usnData["RVCE23BAS037"] = "ROHIT KADAKOL";
    usnData["RVCE23BAS036"] = "S VENKATESH SHENOY";
    usnData["RVCE23BAS030"] = "SANSKAR VERMA";
    usnData["RVCE23BAS014"] = "SARTHAK SHARMA";
    usnData["RVCE23BAS006"] = "SARVIKA RAJU CHAMARTHY";
    usnData["RVCE23BAS029"] = "SHAMBHAVI SHUKLA";
    usnData["RVCE23BAS002"] = "SHANTHOSH K V";
    usnData["RVCE23BAS019"] = "SHASHANK MS";
    usnData["RVCE23BAS056"] = "SHIVA";
    usnData["RVCE23BAS010"] = "SHIVANSH SINGH";
    usnData["RVCE23BAS022"] = "SRUJAN KULKARNI";
    usnData["RVCE23BAS015"] = "SYED ABDUL KHYUOM";
    usnData["RVCE23BAS038"] = "TANAV KUMAR";
    usnData["RVCE23BAS008"] = "TARAN NITHIN RAO";
    usnData["RVCE23BAS054"] = "TEJAS L";
    usnData["RVCE23BAS063"] = "VEDA JAMBIGI";
    usnData["RVCE23BAS048"] = "VISHNU RAGHAVENDRA MANNAPUR";
    usnData["RVCE23BAS057"] = "YASHWANTH R";
    usnData["RVCE23BCH028"] = "ABHIJEET MISHRA";
    usnData["RVCE23BCH030"] = "ADITI AMIT KALLOLKAR";
    usnData["RVCE23BCH011"] = "ADVIKA RASTOGI";
    usnData["RVCE23BCH032"] = "ADVITH";
    usnData["RVCE23BCH039"] = "AKANKSH PEJAVER RAO";
    usnData["RVCE23BCH026"] = "ANUBHAV SHARMA";
    usnData["RVCE23BCH012"] = "ANUSHKA MERWADE";
    usnData["RVCE23BCH024"] = "AYUSH MANISH PATIL";
    usnData["RVCE23BCH005"] = "BENJAMIN VARGHESE ALVIN";
    usnData["RVCE23BCH010"] = "CHERIAN MANAKALATHIL";
    usnData["RVCE23BCH037"] = "CHETAN PHAGOTRA";
    usnData["RVCE23BCH009"] = "CHINTHAN KRISHNA M";
    usnData["RVCE23BCH004"] = "DAMERAS V D S SHALINI";
    usnData["RVCE23BCH008"] = "DEEP BISWAS";
    usnData["RVCE23BCH016"] = "DIVYA UMESH SARVI";
    usnData["RVCE23BCH038"] = "DWISHAN R ACHARYA";
    usnData["RVCE23BCH041"] = "HARSH PODDAR";
    usnData["RVCE23BCH015"] = "HEMANTH HS";
    usnData["RVCE23BCH018"] = "IBRAHIM MUSTHAFA";
    usnData["RVCE23BCH034"] = "KOMALA M";
    usnData["RVCE23BCH017"] = "M MOUNIKA";
    usnData["RVCE23BCH036"] = "MAHI KULKARNI";
    usnData["RVCE23BCH025"] = "MAISHA IMRAN";
    usnData["RVCE23BCH014"] = "MANOJ R";
    usnData["RVCE23BCH040"] = "MEETH B JAIN";
    usnData["RVCE23BCH023"] = "MEGHA THAKUR";
    usnData["RVCE23BCH029"] = "NAVNEET KUMAR";
    usnData["RVCE23BCH013"] = "PRATHAM S TANTRI";
    usnData["RVCE23BCH002"] = "RAGHAV MANJUNATH BHAT";
    usnData["RVCE23BCH031"] = "RAIYANI UTTAM SANJAYBHAI";
    usnData["RVCE23BCH006"] = "ROHAN KIRAN";
    usnData["RVCE23BCH003"] = "SAHIL BOSE";
    usnData["RVCE23BCH035"] = "SIMNAT M";
    usnData["RVCE23BCH033"] = "SINDHU C";
    usnData["RVCE23BCH027"] = "SOUMYA JHA";
    usnData["RVCE23BCH007"] = "SRIPRADA RAMESH";
    usnData["RVCE23BCH019"] = "SUPREET CHANDRAKANT NAIK";
    usnData["RVCE23BCH021"] = "THILAKRATHINAM U";
    usnData["RVCE23BCH001"] = "UMAID RAJ SINGH";
    usnData["RVCE23BCH022"] = "VIJAYKUMAR RAMU KADAM";
    usnData["RVCE23BCH020"] = "VISHAL RATHOD";
    usnData["RVCE23BCH042"] = "ANIRUDH JAGGARAJU";
    usnData["RVCE23BCV042"] = "ABDUL HAKEEM";
    usnData["RVCE23BCV013"] = "ADARSH ABHIRAJ";
    usnData["RVCE23BCV056"] = "AFRID AHMED";
    usnData["RVCE23BCV011"] = "AMISH KUMAR GOWDA";
    usnData["RVCE23BCV044"] = "ANAY SHARMA";
    usnData["RVCE23BCV001"] = "ANIMESH AGRAWAL";
    usnData["RVCE23BCV045"] = "ANJALI";
    usnData["RVCE23BCV049"] = "ANKIT KUMAR";
    usnData["RVCE23BCV050"] = "ANUPAM ANAND";
    usnData["RVCE23BCV014"] = "ARMAAN GOYAL";
    usnData["RVCE23BCV018"] = "ARYAN KIRAN NIPPANIKAR";
    usnData["RVCE23BCV064"] = "BANDRAKALLI KIRAN KUMAR";
    usnData["RVCE23BCV060"] = "BHARGAV U";
    usnData["RVCE23BCV063"] = "BHAVISH S";
    usnData["RVCE23BCV035"] = "BHUMI KHANDELWAL";
    usnData["RVCE23BCV026"] = "BHUVAN V SIRIGERI";
    usnData["RVCE23BCV048"] = "DAKSHAK PRADEEP";
    usnData["RVCE23BCV007"] = "DHANUSH GOWDA C";
    usnData["RVCE23BCV031"] = "DHANUSH PALEGAR N";
    usnData["RVCE23BCV034"] = "E M PAVAN KUMAR";
    usnData["RVCE23BCV002"] = "G K KAVIN ADITHYA";
    usnData["RVCE23BCV066"] = "IG P NAGARJUN";
    usnData["RVCE23BCV046"] = "HITESH CHANDRA";
    usnData["RVCE23BCV033"] = "K DINESH";
    usnData["RVCE23BCV021"] = "KAIF ALI KHAN";
    usnData["RVCE23BCV012"] = "KRITHIN KANNA SHAKTHIVEL";
    usnData["RVCE23BCV052"] = "KUNAL MEHTA";
    usnData["RVCE23BCV062"] = "LEKHANA HR";
    usnData["RVCE23BCV016"] = "MANISH";
    usnData["RVCE23BCV040"] = "MITALI PAL";
    usnData["RVCE23BCV041"] = "MOHAMMAD ZAID MIR";
    usnData["RVCE23BCV023"] = "MOHAMMED ABDUL MUGHEES";
    usnData["RVCE23BCV019"] = "MONISHA SN";
    usnData["RVCE23BCV017"] = "MUTTURAJ PANDIT PUJAR";
    usnData["RVCE23BCV055"] = "NUTHAN HT";
    usnData["RVCE23BCV010"] = "OMKAR PADHI";
    usnData["RVCE23BCV038"] = "PATEL SHWET VISHNUBHAI";
    usnData["RVCE23BCV037"] = "PRACHI SINGH";
    usnData["RVCE23BCV065"] = "PRATEEK MAHANTESH BALIGAR";
    usnData["RVCE23BCV039"] = "PRATYUSH DUBEY";
    usnData["RVCE23BCV054"] = "PREETHAM V J";
    usnData["RVCE23BCV061"] = "PURUSHOTHAMA REDDY M";
    usnData["RVCE23BCV058"] = "S MOUNY GAGAN";
    usnData["RVCE23BCV015"] = "SAMUEL ROLAND FERNANDES";
    usnData["RVCE23BCV029"] = "SANJEEV SURESH NAIK";
    usnData["RVCE23BCV059"] = "SANJITH G S";
    usnData["RVCE23BCV028"] = "SHASHANK PATIL GANDIGI";
    usnData["RVCE23BCV020"] = "SHASHANK S";
    usnData["RVCE23BCV053"] = "SUDHANSHU KUMAR";
    usnData["RVCE23BCV024"] = "SUNIL";
    usnData["RVCE23BCV030"] = "SURYA R GOWDA";
    usnData["RVCE23BCV051"] = "SUYASH TIWARI";
    usnData["RVCE23BCV005"] = "SYED ALTAF";
    usnData["RVCE23BCV022"] = "SYED IMTIYAZ";
    usnData["RVCE23BCV057"] = "TARUN RAGHAV S K";
    usnData["RVCE23BCV006"] = "TECHI NOSSU";
    usnData["RVCE23BCV009"] = "TEJAS G";
    usnData["RVCE23BCV036"] = "THUNGA KUMAR SUJAL";
    usnData["RVCE23BCV043"] = "TUSHAR KUMAR";
    usnData["RVCE23BCV008"] = "VAMSHIV K";
    usnData["RVCE23BCV027"] = "VENKATESH K";
    usnData["RVCE23BCV032"] = "VIJAY RAGHAVENDRASA SHINGRI";
    usnData["RVCE23BCV004"] = "VISHAL PATIL";
    usnData["RVCE23BCV047"] = "YAYAVARAM NARASIMHA SAI SASHANK";
    usnData["RVCE23BCV025"] = "YUVARAJ H R";
    usnData["RVCE23BCV067"] = "MANISH S K";
    usnData["RVCE23BEC016"] = "AADITYA ABHIGYAN";
    usnData["RVCE23BEC165"] = "AASHRITH A RAO";
    usnData["RVCE23BEC079"] = "ABHISHEK";
    usnData["RVCE23BEC114"] = "ABU ARSHIAN";
    usnData["RVCE23BEC020"] = "ADARSH SHANKAR";
    usnData["RVCE23BEC094"] = "ADI SUBODH REDKAR";
    usnData["RVCE23BEC160"] = "ADITYA ANIL BHARADWAJ";
    usnData["RVCE23BEC140"] = "ADITYA BHARDWAJ";
    usnData["RVCE23BEC084"] = "ADITYA MENON";
    usnData["RVCE23BEC169"] = "ADITYA NAGOOR";
    usnData["RVCE23BEC034"] = "AJAY VISWANATHAN S";
    usnData["RVCE23BEC042"] = "AKASH H C";
    usnData["RVCE23BEC076"] = "AKASH SHIVAPPA KUNTOJI";
    usnData["RVCE23BEC166"] = "AMARESH MALGI";
    usnData["RVCE23BEC134"] = "ANAGHA PERINGATHARA RAMESH";
    usnData["RVCE23BEC080"] = "ANANYA R";
    usnData["RVCE23BEC059"] = "ANEESH V BANKAPUR";
    usnData["RVCE23BEC188"] = "ANIL KUMAR";
    usnData["RVCE23BEC045"] = "ANSH A AGADI";
    usnData["RVCE23BEC099"] = "ANSH AGARWAL";
    usnData["RVCE23BEC093"] = "ARJUN SINGH";
    usnData["RVCE23BEC001"] = "ARUMITA NANDI";
    usnData["RVCE23BEC183"] = "ASHUTOSH SHARMA KOTRA";
    usnData["RVCE23BEC150"] = "AVIRAL SRIVASTAV";
    usnData["RVCE23BEC186"] = "AYUSH HEGDE";
    usnData["RVCE23BEC040"] = "AYUSH MS";
    usnData["RVCE23BEC088"] = "B AYUSH";
    usnData["RVCE23BEC152"] = "BHARATH V";
    usnData["RVCE23BEC072"] = "BHOOMIKA C";
    usnData["RVCE23BEC153"] = "BINDUSHREE V P";
    usnData["RVCE23BEC167"] = "CHANDRASHEKHARACHAR M R";
    usnData["RVCE23BEC060"] = "CHINMAY SAVADI";
    usnData["RVCE23BEC144"] = "DARSH KHANNA";
    usnData["RVCE23BEC119"] = "DHANISHTA MINAKSHI NATHAN";
    usnData["RVCE23BEC164"] = "DHIYA JANKY";
    usnData["RVCE23BEC137"] = "DHRUV GUPTA";
    usnData["RVCE23BEC130"] = "DHRUV MIRASKAR";
    usnData["RVCE23BEC002"] = "DHRUVT";
    usnData["RVCE23BEC073"] = "DHRUVA B N";
    usnData["RVCE23BEC116"] = "DHRUVA VISHWANATH HEGDE";
    usnData["RVCE23BEC120"] = "DHRUVI BHANDARI";
    usnData["RVCE23BEC028"] = "DIVIJ JUNEJA";
    usnData["RVCE23BEC132"] = "DRUPAD GIRI";
    usnData["RVCE23BEC037"] = "ESHAAN V MUNGURWADI";
    usnData["RVCE23BEC053"] = "ESHWAR PRASAD M";
    usnData["RVCE23BEC082"] = "G NANDAKISHORE SHANKAR BHARADWAJ";
    usnData["RVCE23BEC092"] = "GAURI";
    usnData["RVCE23BEC026"] = "GUNN MATTA";
    usnData["RVCE23BEC190"] = "GURSIRJAN SINGH";
    usnData["RVCE23BEC071"] = "HS HARSHA";
    usnData["RVCE23BEC108"] = "HARDIK PANERU";
    usnData["RVCE23BEC096"] = "HARI PRASAD L";
    usnData["RVCE23BEC105"] = "HARSHIL KUNDETY";
    usnData["RVCE23BEC103"] = "HEERAL KHARE";
    usnData["RVCE23BEC102"] = "HEMANTH MR";
    usnData["RVCE23BEC014"] = "INIKA RANNA";
    usnData["RVCE23BEC077"] = "J BHARATH CHANDRA";
    usnData["RVCE23BEC017"] = "JAYA SRI JAWAHAR SRIPATHY";
    usnData["RVCE23BEC018"] = "JITESH R";
    usnData["RVCE23BEC004"] = "JOEL SAHA";
    usnData["RVCE23BEC068"] = "K RAVI TEJA";
    usnData["RVCE23BEC005"] = "K V SAI CHARAN";
    usnData["RVCE23BEC123"] = "KAMANA TITIKSHA SIVA PRIYA";
    usnData["RVCE23BEC095"] = "KASANUR PAARTHEEP";
    usnData["RVCE23BEC085"] = "KAUSHAL H";
    usnData["RVCE23BEC046"] = "KRISH NAVEEN";
    usnData["RVCE23BEC021"] = "KRISHNA SAINI";
    usnData["RVCE23BEC010"] = "KSHITHIJ RAO DHENUVAKONDA";
    usnData["RVCE23BEC031"] = "KULKARNI ABHAY PARESH";
    usnData["RVCE23BEC061"] = "LIKHITHA CR";
    usnData["RVCE23BEC115"] = "M NITHYA";
    usnData["RVCE23BEC127"] = "M V AMARNATH";
    usnData["RVCE23BEC185"] = "MANASVI BHAT K";
    usnData["RVCE23BEC139"] = "MANASWI";
    usnData["RVCE23BEC141"] = "MANIK THAPA";
    usnData["RVCE23BEC138"] = "MANISH SHUBHAN";
    usnData["RVCE23BEC055"] = "MANTHAN S BHATT";
    usnData["RVCE23BEC135"] = "MISAB ABDUL RAHEEM";
    usnData["RVCE23BEC086"] = "MODIYAM JAHNAVI";
    usnData["RVCE23BEC015"] = "MONISHA S";
    usnData["RVCE23BEC006"] = "N AKSHAY URS";
    usnData["RVCE23BEC024"] = "NAMAN MANOJ JAIN";
    usnData["RVCE23BEC177"] = "NANDAN M SHEKAR";
    usnData["RVCE23BEC049"] = "NAREN KARTHIK K";
    usnData["RVCE23BEC101"] = "NAREN SRIDHARAN";
    usnData["RVCE23BEC083"] = "NAVYA KJ";
    usnData["RVCE23BEC110"] = "NAVYA SINGH";
    usnData["RVCE23BEC078"] = "NIKHILA E";
    usnData["RVCE23BEC182"] = "NISHAANIH KS";
    usnData["RVCE23BEC030"] = "P SIVA SANTHOSH";
    usnData["RVCE23BEC067"] = "PAVAN G";
    usnData["RVCE23BEC159"] = "PAVAN GOWDA H U";
    usnData["RVCE23BEC036"] = "PHANI SARAN CHALLA";
    usnData["RVCE23BEC051"] = "POORNA CHANDRA B R";
    usnData["RVCE23BEC170"] = "PRAJWAL";
    usnData["RVCE23BEC054"] = "PRAJWAL B K";
    usnData["RVCE23BEC008"] = "PRAJWAL JATHANNA";
    usnData["RVCE23BEC118"] = "PRANAV B HEGDE";
    usnData["RVCE23BEC019"] = "PRANJANA SRIVASTAVA";
    usnData["RVCE23BEC089"] = "PRANSHUL BHARGAVA";
    usnData["RVCE23BEC163"] = "PRASAD C GOUDAR";
    usnData["RVCE23BEC075"] = "PRATHAM M RAO";
    usnData["RVCE23BEC097"] = "PRATHAM MAHADEO PIMPALSHENDE";
    usnData["RVCE23BEC012"] = "PRATHYUSH U";
    usnData["RVCE23BEC122"] = "PREM M";
    usnData["RVCE23BEC029"] = "PRITHVIRAJ";
    usnData["RVCE23BEC129"] = "PRIYA CHANDRAKANT ASUTI";
    usnData["RVCE23BEC048"] = "PRUTHVIRAJ R";
    usnData["RVCE23BEC032"] = "PUNYASHLOKA MAHAPATRA";
    usnData["RVCE23BEC025"] = "PURNENDU JHA";
    usnData["RVCE23BEC147"] = "R CHITHRA";
    usnData["RVCE23BEC104"] = "R SUNIDHI";
    usnData["RVCE23BEC044"] = "RAGHAVA MUKUNDA";
    usnData["RVCE23BEC168"] = "RAGHAVENDRA";
    usnData["RVCE23BEC043"] = "RAHIL KHAN";
    usnData["RVCE23BEC174"] = "RAKSHAA CH";
    usnData["RVCE23BEC172"] = "RANAN AR";
    usnData["RVCE23BEC187"] = "RIITHUN S";
    usnData["RVCE23BEC126"] = "RIYA VIJAYANAND NAIK";
    usnData["RVCE23BEC013"] = "ROHAN JAGADEESHA REDDY";
    usnData["RVCE23BEC154"] = "ROHIT";
    usnData["RVCE23BEC035"] = "ROHIT N KATTI";
    usnData["RVCE23BEC039"] = "ROHIT R IYER";
    usnData["RVCE23BEC111"] = "RONAK KAILASH AGARWAL";
    usnData["RVCE23BEC181"] = "RUPINI HULIKATTI";
    usnData["RVCE23BEC176"] = "S PRAJAN";
    usnData["RVCE23BEC162"] = "SALONI JADHAV";
    usnData["RVCE23BEC011"] = "SAMEER TALLAPRAGADA";
    usnData["RVCE23BEC156"] = "SANCHITHA Y M";
    usnData["RVCE23BEC063"] = "SANJANA T M";
    usnData["RVCE23BEC065"] = "SARATH SANJAY S";
    usnData["RVCE23BEC069"] = "SATHVIK MADAGI";
    usnData["RVCE23BEC158"] = "SATVIK B C";
    usnData["RVCE23BEC117"] = "SEELAM BALA SHANMUKH";
    usnData["RVCE23BEC066"] = "SHASHIDHAR S";
    usnData["RVCE23BEC189"] = "SHISHIR V";
    usnData["RVCE23BEC121"] = "SHIVANSH SHEKHAR";
    usnData["RVCE23BEC133"] = "SHLOK JAIN";
    usnData["RVCE23BEC146"] = "SHREEVATHSA KUTHETHOOR";
    usnData["RVCE23BEC184"] = "SHREYA";
    usnData["RVCE23BEC038"] = "SHREYAS SATISH KUMAR";
    usnData["RVCE23BEC062"] = "SHRIDATTHA M HEBBAR";
    usnData["RVCE23BEC131"] = "SHRIYANSH AGRAWAL";
    usnData["RVCE23BEC109"] = "SHRUTHIKA JAIN S S";
    usnData["RVCE23BEC064"] = "SIDDHARTH SENTHIL KUMAR";
    usnData["RVCE23BEC145"] = "SNEHAS NAYAK";
    usnData["RVCE23BEC178"] = "SOMASHEKHAR SUBHAS BIRADAR";
    usnData["RVCE23BEC148"] = "SPHATIKA S JAIN";
    usnData["RVCE23BEC047"] = "SRI CHARANS";
    usnData["RVCE23BEC090"] = "SRI JANANE S V";
    usnData["RVCE23BEC113"] = "SRIJAN SHARMA";
    usnData["RVCE23BEC091"] = "SRINIDHI HALAHARVI";
    usnData["RVCE23BEC056"] = "SUDEEP P HANDE";
    usnData["RVCE23BEC070"] = "SUDHANSHU H";
    usnData["RVCE23BEC087"] = "SUHANI MAITY";
    usnData["RVCE23BEC107"] = "SUJAL PRAKASH KOLIGUDD";
    usnData["RVCE23BEC157"] = "SUJAN S";
    usnData["RVCE23BEC173"] = "SUJANI LN";
    usnData["RVCE23BEC112"] = "SUMEDH KALLAPUR";
    usnData["RVCE23BEC136"] = "SUROJOTISOM";
    usnData["RVCE23BEC171"] = "SURYA RADHA BALAJI";
    usnData["RVCE23BEC057"] = "T HARSHITHA";
    usnData["RVCE23BEC003"] = "TANDLE SUHANI";
    usnData["RVCE23BEC027"] = "TANMAY KAPOOR";
    usnData["RVCE23BEC058"] = "TANMAY SHARAD JOSHI";
    usnData["RVCE23BEC052"] = "TARUN S K";
    usnData["RVCE23BEC106"] = "TARUSH LADDHA";
    usnData["RVCE23BEC142"] = "TEJAS KUSH";
    usnData["RVCE23BEC100"] = "TEJAS S MATH";
    usnData["RVCE23BEC149"] = "TEJASVI MALLAIAH";
    usnData["RVCE23BEC192"] = "TEJASVI R SHANKAR";
    usnData["RVCE23BEC033"] = "TUMMALAPENTA PHANEESWAR";
    usnData["RVCE23BEC125"] = "UDIT SINGH";
    usnData["RVCE23BEC098"] = "UJJWAL BAJPAI";
    usnData["RVCE23BEC009"] = "V JAYA KRISHNA";
    usnData["RVCE23BEC161"] = "VAIBHAVI D";
    usnData["RVCE23BEC041"] = "VARSHA M";
    usnData["RVCE23BEC175"] = "VIBHEESHA DWARAKANATHAN";
    usnData["RVCE23BEC023"] = "VIBIN DOMINICJ";
    usnData["RVCE23BEC191"] = "VIDHI KHANDELWAL";
    usnData["RVCE23BEC143"] = "VIJAY KUMAR GUPTA";
    usnData["RVCE23BEC081"] = "VINAY A";
    usnData["RVCE23BEC180"] = "VINEET V HAVANUR";
    usnData["RVCE23BEC050"] = "VIPUL S";
    usnData["RVCE23BEC074"] = "VISHWANATHA KM";
    usnData["RVCE23BEC179"] = "YS HARSHAL";
    usnData["RVCE23BEC151"] = "YASH SAGAR";
    usnData["RVCE23BEC022"] = "YATIN SANGWAN";
    usnData["RVCE23BEC155"] = "YOGESH MAHESH BISNAL";
    usnData["RVCE23BEC193"] = "KHUSHI VISHWANATH";
    usnData["RVCE23BEE043"] = "ABHISHEK K CHIMMALAGI";
    usnData["RVCE23BEE025"] = "ADITI AGARWAL";
    usnData["RVCE23BEE037"] = "ADITYA CHACHAN";
    usnData["RVCE23BEE030"] = "ADITYA GOPAL RAO SURAMPALLY";
    usnData["RVCE23BEE024"] = "ADITYA PRATAP";
    usnData["RVCE23BEE031"] = "ADWIT CHANDRA";
    usnData["RVCE23BEE051"] = "AISHWARYA S G";
    usnData["RVCE23BEE052"] = "AKASH RAJ";
    usnData["RVCE23BEE036"] = "AMAN GOEL";
    usnData["RVCE23BEE023"] = "ANAY KATTI";
    usnData["RVCE23BEE061"] = "ARAVIND KUMAR N";
    usnData["RVCE23BEE034"] = "ARNAV SAXENA";
    usnData["RVCE23BEE041"] = "ARYAMAN";
    usnData["RVCE23BEE018"] = "ARYAN B NAIK";
    usnData["RVCE23BEE010"] = "CHAROO RANJAN";
    usnData["RVCE23BEE054"] = "DATTATREYA";
    usnData["RVCE23BEE042"] = "DRISHTI KHANDELWAL";
    usnData["RVCE23BEE003"] = "HARDIK G D";
    usnData["RVCE23BEE046"] = "HEMANTH KUMAR NAYAK S";
    usnData["RVCE23BEE044"] = "KEERTHAN S N";
    usnData["RVCE23BEE048"] = "KEERTHANA S S";
    usnData["RVCE23BEE005"] = "KRUTHIKA P JAYSWAL";
    usnData["RVCE23BEE028"] = "LAKSHI NANDWANA";
    usnData["RVCE23BEE038"] = "MAHI WARDE";
    usnData["RVCE23BEE015"] = "MOHAMMAD ISAQ";
    usnData["RVCE23BEE035"] = "NISHANT V H";
    usnData["RVCE23BEE002"] = "OJASVI DESAI";
    usnData["RVCE23BEE059"] = "PAVANKUMAR PATTAR";
    usnData["RVCE23BEE020"] = "POORVIKA N";
    usnData["RVCE23BEE033"] = "POTTA SIDDHARTH";
    usnData["RVCE23BEE004"] = "PRANAV KAMATH";
    usnData["RVCE23BEE060"] = "PRANAV PRASHANTH KAMATH";
    usnData["RVCE23BEE022"] = "PRANAV PRATYUSH";
    usnData["RVCE23BEE001"] = "PRITAM KUMAR";
    usnData["RVCE23BEE012"] = "RISHI SHIVAKUMAR GOUDA";
    usnData["RVCE23BEE056"] = "RITESH RAVINDRA KUMAR";
    usnData["RVCE23BEE050"] = "SACHIN GOWDA US";
    usnData["RVCE23BEE062"] = "SANDESH RAVINDRA GUNAPAL";
    usnData["RVCE23BEE049"] = "SANEHA SHARMA";
    usnData["RVCE23BEE008"] = "SATYAM SINHA";
    usnData["RVCE23BEE058"] = "SETHUS";
    usnData["RVCE23BEE027"] = "SHAROAN LUKE SHIBU";
    usnData["RVCE23BEE047"] = "SHRADHA NAGESHWAR";
    usnData["RVCE23BEE009"] = "SHRAVANTH M R";
    usnData["RVCE23BEE039"] = "SHREEYA SUMAN";
    usnData["RVCE23BEE029"] = "SHREYA BALI";
    usnData["RVCE23BEE006"] = "SIDDHARTH KRISHNA";
    usnData["RVCE23BEE040"] = "SOUSHILYA KOLEY";
    usnData["RVCE23BEE045"] = "SUBHAM SEN";
    usnData["RVCE23BEE011"] = "SUPRATIM MUKHERJEE";
    usnData["RVCE23BEE053"] = "TEJAS KS";
    usnData["RVCE23BEE013"] = "VAIBHAVKUMAR BHURA";
    usnData["RVCE23BEE014"] = "VARSHINI C B";
    usnData["RVCE23BEE017"] = "VEDANT";
    usnData["RVCE23BEE007"] = "VEDANTA MUKHERJEE";
    usnData["RVCE23BEE019"] = "VEDANTH S";
    usnData["RVCE23BEE063"] = "VEETHI";
    usnData["RVCE23BEE032"] = "VIGNESH MISHRA";
    usnData["RVCE23BEE057"] = "VINAYAK VIJAY KULKARNI";
    usnData["RVCE23BEE016"] = "VRAJESH C SALIAN";
    usnData["RVCE23BEE055"] = "WASE ALEEM MULLA";
    usnData["RVCE23BEE021"] = "YASIR SHARIFF";
    usnData["RVCE23BEE064"] = "ISHITVA SINGH";
    usnData["RVCE23BEE065"] = "ISHAAN ANAND";
    usnData["RVCE23BEE066"] = "DESHMUKH PIYUSH YASHVANT";
    usnData["RVCE23BEI024"] = "AASHWIN SINGH";
    usnData["RVCE23BEI011"] = "ADITEYA SARKAR";
    usnData["RVCE23BE1004"] = "ADITYA BALAN";
    usnData["RVCE23BEI034"] = "ADITYA C";
    usnData["RVCE23BE1029"] = "ADITYA MAURYA";
    usnData["RVCE23BE1056"] = "AKSHATA";
    usnData["RVCE23BE1059"] = "ANIRUDH BHARADWAJ";
    usnData["RVCE23BE1018"] = "ANKIT JAJOO";
    usnData["RVCE23BEI036"] = "ARNAV SINGHAL";
    usnData["RVCE23BEI042"] = "ARUN KUMAR M";
    usnData["RVCE23BEI032"] = "ARYAN DHAWAN";
    usnData["RVCE23BE1043"] = "B AISHWARYA NAYAK";
    usnData["RVCE23BE1008"] = "B V VINITH";
    usnData["RVCE23BEI017"] = "BHIM SINGH";
    usnData["RVCE23BE1054"] = "DEEPTHI PRASAD";
    usnData["RVCE23BE1055"] = "DIVYA PRAKASH";
    usnData["RVCE23BEI051"] = "DIVYA T";
    usnData["RVCE23BEI010"] = "GOKUL ADITHYA S";
    usnData["RVCE23BE1062"] = "HARSH VARDHAN CHOUDHARY";
    usnData["RVCE23BEI031"] = "HARSHIT BUCHASIA";
    usnData["RVCE23BEI033"] = "HITESH BHARTIA";
    usnData["RVCE23BEI020"] = "ISMAIL WARSI";
    usnData["RVCE23BE1050"] = "KARTHIK R HEGDE";
    usnData["RVCE23BEI035"] = "KARUNYA SREENIVAS";
    usnData["RVCE23BE1005"] = "KEERTHIU K";
    usnData["RVCE23BE1057"] = "KOMMIRI SRINATH";
    usnData["RVCE23BEI026"] = "KRISHNA PURWAR";
    usnData["RVCE23BE1001"] = "KSHEERAJA KESHAV ADYA";
    usnData["RVCE23BEI023"] = "MANAS PANJWANI";
    usnData["RVCE23BEI014"] = "MANASWINI S";
    usnData["RVCE23BE1006"] = "MAYANK S PANDEY";
    usnData["RVCE23BE1049"] = "MD OWAIS ASHRAF";
    usnData["RVCE23BEI044"] = "MOHAMMED FIRASATH KHAN";
    usnData["RVCE23BEI027"] = "MUHAMMAD AMMAR SIDDIQUI";
    usnData["RVCE23BE1038"] = "NAKUL YADAV";
    usnData["RVCE23BE1063"] = "NAVEEN S";
    usnData["RVCE23BE1052"] = "NISHITA SINGHVI";
    usnData["RVCE23BE1047"] = "PAVAN G";
    usnData["RVCE23BE1041"] = "POORVIKA B";
    usnData["RVCE23BE1046"] = "PRATHAMESH";
    usnData["RVCE23BE1045"] = "PRATHIK P KEKARE";
    usnData["RVCE23BE1009"] = "PRIYAL KHANDELWAL";
    usnData["RVCE23BEI022"] = "PRIYANSHU DEEPAK";
    usnData["RVCE23BEI037"] = "RAGHUVANSH DEV ATRI";
    usnData["RVCE23BE1021"] = "RISHAV RAJ SINGH";
    usnData["RVCE23BE1007"] = "ROSHAN SARMAH";
    usnData["RVCE23BEI003"] = "SAHAS S KERUDI";
    usnData["RVCE23BEI040"] = "SHAMITHA M S";
    usnData["RVCE23BE1016"] = "SHARATH M H";
    usnData["RVCE23BE1039"] = "SHRAVAN SHAILESH TALAPADY";
    usnData["RVCE23BE1019"] = "SIDDHANT KASHYAP";
    usnData["RVCE23BE1025"] = "SIDDHANT SINGH";
    usnData["RVCE23BE1012"] = "SUDARSHAN A N";
    usnData["RVCE23BEI015"] = "SUPRITHA JAIN J P";
    usnData["RVCE23BE1048"] = "SURENDRA BAGALI";
    usnData["RVCE23BEI013"] = "SYED FAHIMUDDIN";
    usnData["RVCE23BE1053"] = "T S PRARTHANA RAO";
    usnData["RVCE23BE1060"] = "UJWALA М НАККАРАККІ";
    usnData["RVCE23BEI028"] = "VARDHAN SUDHIR PATIL";
    usnData["RVCE23BE1058"] = "VIDYASHREE N";
    usnData["RVCE23BE1002"] = "VIJAYALAXMI ASHOK PATIL";
    usnData["RVCE23BE1064"] = "VIKAS JOSHI";
    usnData["RVCE23BE1061"] = "YASHAS S SHELLIKERI";
    usnData["RVCE23BE1065"] = "VISHWAPRIYA R";
    usnData["RVCE23BTE025"] = "AAHANA NISCHAL";
    usnData["RVCE23BTE005"] = "AARUSH M";
    usnData["RVCE23BTE017"] = "ABDUL REHMAN";
    usnData["RVCE23BTE028"] = "ADITHYA SAKTHIMANI";
    usnData["RVCE23BTE046"] = "AMARESH H";
    usnData["RVCE23BTE020"] = "AMIT";
    usnData["RVCE23BTE038"] = "ANADEE YADAV";
    usnData["RVCE23BTE004"] = "ANIRUDH KULKARNI";
    usnData["RVCE23BTE006"] = "ANURAG SRINATH";
    usnData["RVCE23BTE057"] = "ANWITHA VISHWANATH";
    usnData["RVCE23BTE030"] = "ARAV JHA";
    usnData["RVCE23BTE048"] = "ARNAV S GOWDA";
    usnData["RVCE23BTE012"] = "AYUSHMAAN GUPTA";
    usnData["RVCE23BTE042"] = "BRIJESH C";
    usnData["RVCE23BTE036"] = "CHINMAY SHARMA";
    usnData["RVCE23BTE029"] = "DEEP DYOTAK DASH";
    usnData["RVCE23BTE011"] = "HARJYOTI BAISHYA";
    usnData["RVCE23BTE007"] = "HARSHIT SAROHA";
    usnData["RVCE23BTE022"] = "KASHYAP SRIRAM";
    usnData["RVCE23BTE059"] = "LIKITH K S";
    usnData["RVCE23BTE023"] = "MANAV VERMA";
    usnData["RVCE23BTE019"] = "NAVYA PA";
    usnData["RVCE23BTE050"] = "NIKHILESH RAO";
    usnData["RVCE23BTE013"] = "NIKHITHA M";
    usnData["RVCE23BTE049"] = "PAVAN S ARADHYA";
    usnData["RVCE23BTE060"] = "PETA SAI SRI HARSHITH";
    usnData["RVCE23BTE040"] = "PRADYUMNA BENDIGERI";
    usnData["RVCE23BTE047"] = "PRANAV";
    usnData["RVCE23BTE045"] = "PREETHAM V";
    usnData["RVCE23BTE058"] = "PRIYANKA N UDAY";
    usnData["RVCE23BTE039"] = "RIK SETH";
    usnData["RVCE23BTE014"] = "RITHWIK RAVINDRA KUMAR";
    usnData["RVCE23BTE055"] = "RITVIK UNNIKRISHNAN";
    usnData["RVCE23BTE053"] = "S PRANESH";
    usnData["RVCE23BTE051"] = "S SHREYA";
    usnData["RVCE23BTE016"] = "SAMEERA SIMHAH R";
    usnData["RVCE23BTE018"] = "SANJAY CM";
    usnData["RVCE23BTE031"] = "SESHASAI CHILLARA";
    usnData["RVCE23BTE001"] = "SHARAN SHETTY";
    usnData["RVCE23BTE024"] = "SHIVEN SINGH";
    usnData["RVCE23BTE056"] = "SHREYA HANIMANAL";
    usnData["RVCE23BTE044"] = "SHREYA J PATIL";
    usnData["RVCE23BTE043"] = "SIDHARTH GHOSH";
    usnData["RVCE23BTE035"] = "SNEHA PANDEY";
    usnData["RVCE23BTE041"] = "SONIA GIRISH DESHPANDE";
    usnData["RVCE23BTE033"] = "SOUMOJEET KUNDU";
    usnData["RVCE23BTE026"] = "SRINIDHI SURESH";
    usnData["RVCE23BTE002"] = "SRIVATSA B JANADRI";
    usnData["RVCE23BTE003"] = "SUDHANVAR B P";
    usnData["RVCE23BTE009"] = "SUHAS SRIVATSA Y";
    usnData["RVCE23BTE032"] = "SURYANSH TRIPATHI";
    usnData["RVCE23BTE010"] = "TANUSHREE C";
    usnData["RVCE23BTE034"] = "UNMESH RAJ";
    usnData["RVCE23BTE008"] = "UTKARSH VIHAN";
    usnData["RVCE23BTE054"] = "V MEGHA";
    usnData["RVCE23BTE037"] = "VARDHMAN TRIPATHI";
    usnData["RVCE23BTE015"] = "VEERABHADRAPPA DALAL";
    usnData["RVCE23BTE052"] = "VIBHASHREE VASUKI";
    usnData["RVCE23BTE021"] = "VIJAY SUDARSHAN B";
    usnData["RVCE23BTE027"] = "VINEET RAJ";
    usnData["RVCE23BTE061"] = "VRINDA V KATTI";
    usnData["RVCE23BTE062"] = "S R ABHISHEK";
    usnData["RVCE23BTE063"] = "C VARSHA";
    usnData["RVCE23BIM008"] = "AADARSH P NAVALGUND";
    usnData["RVCE23BIM010"] = "AADITYA AJ";
    usnData["RVCE23BIM019"] = "ABHILASH L PATTAR";
    usnData["RVCE23BIM028"] = "ADARSH A THOMAS";
    usnData["RVCE23BIM039"] = "ADITYA KAUSHIK G V";
    usnData["RVCE23BIM051"] = "ANANYA HIREMATH";
    usnData["RVCE23BIM024"] = "ANCHAL KARANANI";
    usnData["RVCE23BIM043"] = "ANURADHA E";
    usnData["RVCE23BIM047"] = "ANUSH D N";
    usnData["RVCE23BIM005"] = "ARITRA BHATTACHARYA";
    usnData["RVCE23BIM015"] = "ATHARV MAYUR SHAHA";
    usnData["RVCE23BIM062"] = "BHAVISH H RAJANI";
    usnData["RVCE23BIM049"] = "CHAITHAN GOWDA R";
    usnData["RVCE23BIM052"] = "DHEERAJ ARADHYA M";
    usnData["RVCE23BIM060"] = "G M BINDU";
    usnData["RVCE23BIM007"] = "GAURIKA ANEKAR";
    usnData["RVCE23BIM013"] = "GOWRIS GOUDA";
    usnData["RVCE23BIM054"] = "HEMANTH N D";
    usnData["RVCE23BIM042"] = "JAIPREETH J";
    usnData["RVCE23BIM004"] = "JEEVAN N SASTRY";
    usnData["RVCE23BIM003"] = "KAARTHAVYA KOMPAL";
    usnData["RVCE23BIM029"] = "KAUSHIK GUPTA";
    usnData["RVCE23BIM021"] = "KAVYA M G";
    usnData["RVCE23BIM018"] = "KEERTHANA R SINGH";
    usnData["RVCE23BIM053"] = "L M YASHWANTH ";
    usnData["RVCE23BIM006"] = "LEANN MAREILA P";
    usnData["RVCE23BIM012"] = "LIKHITH G NAIK";
    usnData["RVCE23BIM040"] = "LUNAGARIYA ROHAN DHIRAJBHAI";
    usnData["RVCE23BIM027"] = "MAINAK SEN";
    usnData["RVCE23BIM020"] = "MANASA";
    usnData["RVCE23BIM046"] = "MANOGYNA N";
    usnData["RVCE23BIM059"] = "MANUTS";
    usnData["RVCE23BIM033"] = "MOHAMMED IQBAL";
    usnData["RVCE23BIM016"] = "P SANJANA";
    usnData["RVCE23BIM055"] = "PRABHAV RAJAN";
    usnData["RVCE23BIM034"] = "PRANSHU SHALEEN";
    usnData["RVCE23BIM056"] = "PRASHANTH KABIN SELVAM";
    usnData["RVCE23BIM023"] = "PRIYANSHU KUMAR";
    usnData["RVCE23BIM002"] = "RS KRUPA";
    usnData["RVCE23BIM045"] = "RAJU BASAGONDA SHEGAVE";
    usnData["RVCE23BIM036"] = "RISHIKESH R AKKI";
    usnData["RVCE23BIM031"] = "RIYA JAISWAL";
    usnData["RVCE23BIM038"] = "ROSHNI SANJAY";
    usnData["RVCE23BIM009"] = "SAPNA B G";
    usnData["RVCE23BIM026"] = "SHREE MAHESHWARI";
    usnData["RVCE23BIM025"] = "SHREYA KALYANEE";
    usnData["RVCE23BIM030"] = "SHRI RANG PAI";
    usnData["RVCE23BIM032"] = "SIDDHANT YADAV ";
    usnData["RVCE23BIM022"] = "SRIVIDYA SRIRAMAN";
    usnData["RVCE23BIM017"] = "SUSHMITHAS";
    usnData["RVCE23BIM058"] = "TEJASKAND G S";
    usnData["RVCE23BIM050"] = "TIRUVALLI KUMAR SAI";
    usnData["RVCE23BIM057"] = "V K DIKSHA KARAN";
    usnData["RVCE23BIM048"] = "V NITHIN CHAKRAVARTHI";
    usnData["RVCE23BIM037"] = "VIDHAAN JAIN";
    usnData["RVCE23BIM044"] = "VINAYAKA ANANTH HEGDE";
    usnData["RVCE23BIM014"] = "VISHAL M";
    usnData["RVCE23BIM011"] = "VISHNU BHARADWAJ KASHYAP";
    usnData["RVCE23BIM061"] = "VISHNU PRIYA TU";
    usnData["RVCE23BIM001"] = "VISHNU VARDHAN REDDY M";
    usnData["RVCE23BIM041"] = "YUKTA SATHEESH N";
    usnData["RVCE23BIM035"] = "YUV KHATRI";
    usnData["RVCE23BIM063"] = "MITHUN KUMAR K";
    usnData["RVCE23BME024"] = "AANIKA PANDEY";
    usnData["RVCE23BME129"] = "AAROH RASTOGI";
    usnData["RVCE23BME065"] = "AARUSH JAISWAL";
    usnData["RVCE23BME120"] = "ABHINANDAN APPASAHEB NANDAGAVE";
    usnData["RVCE23BME080"] = "ABHINAV KUMAR";
    usnData["RVCE23BME066"] = "ABHINAV SRINIVAS POTHARAJU";
    usnData["RVCE23BME075"] = "ABHISHEK GUPTA";
    usnData["RVCE23BME096"] = "ABIR MANDAL";
    usnData["RVCE23BME002"] = "ACHINTHYA G KADEKAR";
    usnData["RVCE23BME076"] = "ADITHYA M KARTHIK";
    usnData["RVCE23BME034"] = "ADITYA K";
    usnData["RVCE23BME045"] = "ADITYA VIJAYAN";
    usnData["RVCE23BME087"] = "ADITYA VINAY NAIR";
    usnData["RVCE23BME105"] = "AISHWARYA";
    usnData["RVCE23BME068"] = "AITIJHYA SAHOO";
    usnData["RVCE23BME116"] = "AKASH US";
    usnData["RVCE23BME064"] = "AKSHAD AMOL JAGDALE";
    usnData["RVCE23BME067"] = "AMAN KUMAR GUPTA";
    usnData["RVCE23BME037"] = "AMOGH P GIRI";
    usnData["RVCE23BME093"] = "ANIRUDH HULIGERI";
    usnData["RVCE23BME009"] = "ANIRUDH KOLLIPARA";
    usnData["RVCE23BME005"] = "ANSHUL JOSHI";
    usnData["RVCE23BME127"] = "ARAVIND PRAGOUDA PATIL";
    usnData["RVCE23BME126"] = "ARYAN V DANAWADKAR";
    usnData["RVCE23BME084"] = "ASHMIT BANSAL";
    usnData["RVCE23BME077"] = "ASHRAF ALI";
    usnData["RVCE23BME062"] = "ATHARVA SRIVASTAVA";
    usnData["RVCE23BME086"] = "AYUSH";
    usnData["RVCE23BME007"] = "AYUSH K KALAGOND";
    usnData["RVCE23BME026"] = "AYUSH MISHRA";
    usnData["RVCE23BME016"] = "AYUSH SATISH INGAVALE";
    usnData["RVCE23BME028"] = "BHOOMIREDDY VENKATA NARASIMHA REDDY";
    usnData["RVCE23BME097"] = "BHOOMITH GOWDA NARENDRAKUMAR";
    usnData["RVCE23BME046"] = "BHUVAN SU";
    usnData["RVCE23BME021"] = "BHUVAN VASU";
    usnData["RVCE23BME079"] = "BULUSU VYAGHRI RAMACHANDRA VIVEK";
    usnData["RVCE23BME099"] = "CH DUSHYANTH RAJ";
    usnData["RVCE23BME032"] = "CHANDRAN SULPI";
    usnData["RVCE23BME106"] = "CHETAN CHANAVEERAGOUDRA";
    usnData["RVCE23BME109"] = "CHETHAN R";
    usnData["RVCE23BME059"] = "CHINMAY PATHAK";
    usnData["RVCE23BME053"] = "CHINTHAN KA";
    usnData["RVCE23BME010"] = "DEVANSH SHAIVAL SHAH";
    usnData["RVCE23BME070"] = "DIVYAM CHHETRI";
    usnData["RVCE23BME102"] = "DIYA SUNILKUMAR GUNAKI";
    usnData["RVCE23BME121"] = "G K ADITYA";
    usnData["RVCE23BME006"] = "GOPAL REDDY";
    usnData["RVCE23BME095"] = "HARINANDAN A";
    usnData["RVCE23BME083"] = "HARINI SARAVANAN";
    usnData["RVCE23BME029"] = "HARSHAVARDHAN PREMKUMAR";
    usnData["RVCE23BME012"] = "HARSHAVARDHAN YALE";
    usnData["RVCE23BME020"] = "K M TALIN THIMMAIAH";
    usnData["RVCE23BME094"] = "KALP RAVAL";
    usnData["RVCE23BME011"] = "KIRUTHIKRAM PS";
    usnData["RVCE23BME125"] = "KISHAN KUMAR U";
    usnData["RVCE23BME063"] = "KISLAY";
    usnData["RVCE23BME110"] = "KRISHNA RASTOGI";
    usnData["RVCE23BME069"] = "KUNAL RAJ";
    usnData["RVCE23BME047"] = "KUNAL RATHOD";
    usnData["RVCE23BME031"] = "LEN ACHAIAH K M";
    usnData["RVCE23BME017"] = "LIKHITH M";
    usnData["RVCE23BME039"] = "LOK RANJAN P N";
    usnData["RVCE23BME113"] = "MADHURA RAO K S";
    usnData["RVCE23BME128"] = "MAHESH";
    usnData["RVCE23BME048"] = "MAHESHAPPA";
    usnData["RVCE23BME058"] = "MALLIKARJUN";
    usnData["RVCE23BME108"] = "MALLIKARJUN J S";
    usnData["RVCE23BME054"] = "MANAS SENTHIL KUMAR";
    usnData["RVCE23BME124"] = "MANVANTH BELAGERE H M";
    usnData["RVCE23BME025"] = "MOHAMMAD LIYAN RAWAT";
    usnData["RVCE23BME052"] = "NAMRATHA E";
    usnData["RVCE23BME073"] = "NARUMANCHI SAI SUDHAMSH";
    usnData["RVCE23BME123"] = "NAYANA H";
    usnData["RVCE23BME041"] = "NIHAL SATHISH";
    usnData["RVCE23BME008"] = "NIKHIL NAGENDRA KASHYAP";
    usnData["RVCE23BME081"] = "OMKAR DAS";
    usnData["RVCE23BME044"] = "PANCHAYYA";
    usnData["RVCE23BME050"] = "PANYAM CHETAN SAI ANIRV";
    usnData["RVCE23BME027"] = "PARTH DUTT VATSA ";
    usnData["RVCE23BME040"] = "PRAGNYA BALIJEPALLI";
    usnData["RVCE23BME035"] = "PRAHLAD SATYANARAYANAN PESHWE";
    usnData["RVCE23BME051"] = "PRAJWALJ";
    usnData["RVCE23BME114"] = "PRASANNA J NAIK";
    usnData["RVCE23BME115"] = "PREETHAM PARAVASTU ";
    usnData["RVCE23BME085"] = "RAGHAV MAHAWAR";
    usnData["RVCE23BME030"] = "RANJITH D S";
    usnData["RVCE23BME038"] = "ROHAN S";
    usnData["RVCE23BME098"] = "ROHIT";
    usnData["RVCE23BME117"] = "ROHITH PS";
    usnData["RVCE23BME056"] = "ROHITH S";
    usnData["RVCE23BME088"] = "RUTRANK TANDON";
    usnData["RVCE23BME118"] = "SAHIL ANAND KOTIAN";
    usnData["RVCE23BME057"] = "SAI HARSHA REDDY G K";
    usnData["RVCE23BME122"] = "SAMARTH VISHWANATH";
    usnData["RVCE23BME049"] = "SAMITH B S ";
    usnData["RVCE23BME033"] = "SANTOSH R";
    usnData["RVCE23BME101"] = "SATHVIK SUKEETH NAIK";
    usnData["RVCE23BME060"] = "SATKRIT SAMYAAN";
    usnData["RVCE23BME072"] = "SAURAV RAJ";
    usnData["RVCE23BME104"] = "SHASHANK B NAIK";
    usnData["RVCE23BME111"] = "SHRAVAN CS";
    usnData["RVCE23BME103"] = "SHREYAS ADITHYA";
    usnData["RVCE23BME100"] = "SIDDAROODH";
    usnData["RVCE23BME071"] = "SIDDHANT SHAH";
    usnData["RVCE23BME043"] = "SMRITIJ ABRAHAM";
    usnData["RVCE23BME014"] = "SOHAN T";
    usnData["RVCE23BME018"] = "SRAJ PRAGNESH PATEL";
    usnData["RVCE23BME003"] = "SRIKAR V INAMDAR";
    usnData["RVCE23BME078"] = "STANZIN CHOKRAP";
    usnData["RVCE23BME061"] = "SUBHENDU KARMAKAR";
    usnData["RVCE23BME074"] = "SUBHRADEEP MONDAL";
    usnData["RVCE23BME022"] = "SUDHANVA PATIL";
    usnData["RVCE23BME119"] = "SUHAS H C";
    usnData["RVCE23BME089"] = "SUYASH TRIVEDI";
    usnData["RVCE23BME055"] = "SYED ABDUR REHMAN";
    usnData["RVCE23BME107"] = "TEJAS V";
    usnData["RVCE23BME019"] = "THOMAS AUGUSTINE";
    usnData["RVCE23BME082"] = "UDAY CHAUDHARY";
    usnData["RVCE23BME092"] = "UTKARSH ASHISH PANDEY";
    usnData["RVCE23BME112"] = "VINITH PRABHU";
    usnData["RVCE23BME023"] = "VISHAL KUMAR SINGH";
    usnData["RVCE23BME013"] = "VISHWAS V RAYAS";
    usnData["RVCE23BME036"] = "YADHUNANDAN HEGDE";
    usnData["RVCE23BME015"] = "YASH PRASHANT MISTRY";
    usnData["RVCE23BME090"] = "YASHAS MADHUKAR NAIK";
    usnData["RVCE23BME042"] = "YASHASWINI S";
    usnData["RVCE23BME130"] = "CHAITANYA KHANDELWAL";

    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText* usnLabel = new wxStaticText(panel, wxID_ANY, "Enter USN:");
    usnInput = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(100, 23), 0);
    wxBoxSizer* centerSizer = new wxBoxSizer(wxHORIZONTAL);
    centerSizer->AddStretchSpacer();
    centerSizer->Add(usnInput, 0, wxALL | wxALIGN_CENTER, 5);
    centerSizer->AddStretchSpacer();
    wxButton* verifyButton = new wxButton(panel, wxID_ANY, "Verify");

    // Move the "Verify" button closer to the input box
    wxBoxSizer* buttonSizer = new wxBoxSizer(wxHORIZONTAL);

    buttonSizer->AddStretchSpacer();
    buttonSizer->Add(verifyButton, 0, wxALL | wxALIGN_CENTER, 10); // Adjust the spacing (e.g., 10)
    buttonSizer->AddStretchSpacer();

    mainSizer->Add(usnLabel, 0, wxALL | wxALIGN_CENTER, 5);
    mainSizer->Add(centerSizer, 1, wxEXPAND);
    mainSizer->Add(buttonSizer, 0, wxEXPAND);

    panel->SetSizer(mainSizer);

    Bind(wxEVT_BUTTON, &VerificationFrame::OnVerify, this, verifyButton->GetId());
    Bind(wxEVT_CLOSE_WINDOW, &VerificationFrame::OnClose, this);

    // Create the search frame but don't show it yet
    searchFrame = new SearchFrame("Search Frame", wxDefaultPosition, wxSize(500, 300));
    searchFrame->Hide();
}

void VerificationFrame::OnVerify(wxCommandEvent& event)
{
    wxString enteredUSN = usnInput->GetValue();

    auto it = usnData.find(enteredUSN);
    if (it != usnData.end())
    {
        wxString name = it->second;
        wxMessageBox(wxString::Format("Verified! Welcome %s", name), "Verification", wxOK | wxICON_INFORMATION);

        searchFrame->Show();

    }
    else
    {
        wxMessageBox("Incorrect USN. Please enter the correct USN.", "Verification", wxOK | wxICON_ERROR);
    }
}

void VerificationFrame::OnClose(wxCloseEvent& event)
{
    // Close the search frame if it's open
    if (searchFrame->IsShown())
    {
        searchFrame->Close();
    }
    Destroy();
}

class VerificationApp : public wxApp
        {
public:
    virtual bool OnInit()
    {
        wxSize screenSize = wxGetDisplaySize();
        wxPoint centerPosition(screenSize.GetWidth() / 2, screenSize.GetHeight() / 2);
        VerificationFrame* frame = new VerificationFrame("USN Verification", wxPoint(550, 400), wxSize(400, 200));
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(VerificationApp);
