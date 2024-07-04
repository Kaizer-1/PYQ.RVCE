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
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2020" && semester == "Semester 1")
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2021" && semester == "Semester 1")
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2022" && semester == "Semester 1")
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2023" && semester == "Semester 1")
        {
            wxString link = "sample-link";
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
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2022" && semester == "Semester 2")
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Math" && year == "2023" && semester == "Semester 2")
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Physics" && (year == "2023" || "2022" || "2021" || "2020" || "2019") && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Chemistry" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Chemistry" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Chemistry" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Chemistry" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Chemistry" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Mechanical" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Mechanical" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Mechanical" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Mechanical" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Mechanical" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electrical" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electrical" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electrical" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electrical" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electrical" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electronics" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electronics" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electronics" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electronics" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Electronics" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Civil" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Civil" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Civil" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Civil" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "Civil" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "C" && year == "2019" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "C" && year == "2020" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "NOT AVAILABLE";
            linkDisplay->SetValue(link);
        }
        else if(subject == "C" && year == "2021" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "C" && year == "2022" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
            linkDisplay->SetValue(link);
        }
        else if(subject == "C" && year == "2023" && (semester == "Semester 1" || "Semester 2"))
        {
            wxString link = "sample-link";
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

    usnData[""] = "Kaizer Dewaswala";
    

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
