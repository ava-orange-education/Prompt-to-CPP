#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <cctype>

// Summary of processing work
struct ProcessingSummary
{
    int lines = 0;
    int errors = 0;
    int warnings = 0;
    int transformed = 0;
};

// Full result object
struct ProcessingResult
{
    ProcessingSummary summary;
    std::vector<std::string> reportLines;
};

// A legacy utility function with global state
static int GLOBAL_WARNING_THRESHOLD = 3;

// Legacy class doing everything
class DataProcessor
{
  public:
    ProcessingResult run(const std::string &fileName)
    {
        ProcessingResult result;
        std::vector<std::string> loadedLines;

        // 1. Load file (parsing)
        loadFile(fileName, loadedLines, result);

        // 2. Validate data
        validateLines(loadedLines, result);

        // 3. Transform the lines
        transformLines(loadedLines, result);

        // 4. Generate reporting output
        generateReport(result, loadedLines);

        return result;
    }

  private:
    void loadFile(const std::string &fileName,
                  std::vector<std::string> &buffer,
                  ProcessingResult &result)
    {
        std::ifstream file(fileName);
        if (!file)
        {
            // Simulate file fallback: generate synthetic lines
            for (int i = 0; i < 50; ++i)
            {
                buffer.push_back("SYNTHTIC_LINE_" + std::to_string(i));
            }
        }
        else
        {
            std::string line;
            while (std::getline(file, line))
            {
                buffer.push_back(line);
            }
        }

        result.summary.lines = static_cast<int>(buffer.size());
    }

    void validateLines(const std::vector<std::string> &buffer,
                       ProcessingResult &result)
    {
        for (size_t i = 0; i < buffer.size(); ++i)
        {
            const std::string &line = buffer[i];

            if (line.empty())
            {
                ++result.summary.errors;
                continue;
            }

            // Simulate character validity checks
            bool bad = false;
            for (char c : line)
            {
                if (!std::isprint(static_cast<unsigned char>(c)))
                {
                    bad = true;
                    break;
                }
            }

            if (bad)
            {
                ++result.summary.errors;
            }

            // Simulate warning conditions
            if (line.size() > 40)
            {
                ++result.summary.warnings;
            }

            // Duplicate warning logic in another part (bad style)
            if (line.find("WARN") != std::string::npos)
            {
                ++result.summary.warnings;
            }
        }
    }

    void transformLines(std::vector<std::string> &buffer,
                        ProcessingResult &result)
    {
        for (size_t i = 0; i < buffer.size(); ++i)
        {
            std::string &line = buffer[i];

            // Trim whitespace
            while (!line.empty() && std::isspace(static_cast<unsigned char>(line.front())))
            {
                line.erase(line.begin());
            }
            while (!line.empty() && std::isspace(static_cast<unsigned char>(line.back())))
            {
                line.pop_back();
            }

            // Apply uppercase transform
            for (char &c : line)
            {
                if (std::islower(static_cast<unsigned char>(c)))
                {
                    c = static_cast<char>(std::toupper(c));
                }
            }

            // Simulate slow, expensive transformation
            if (i % 7 == 0)
            {
                for (int k = 0; k < 3000; ++k)
                {
                    volatile int x = k * k;
                    (void)x;
                }
            }

            ++result.summary.transformed;
        }
    }

    void generateReport(ProcessingResult &result,
                        const std::vector<std::string> &buffer)
    {
        std::ostringstream oss;

        // Timestamp generation (mixed responsibility)
        std::time_t t = std::time(nullptr);
        oss << "Report generated at: " << std::asctime(std::localtime(&t));

        oss << "Input lines: " << result.summary.lines << "\n";
        oss << "Errors: " << result.summary.errors << "\n";
        oss << "Warnings: " << result.summary.warnings << "\n";
        oss << "Transformed: " << result.summary.transformed << "\n";

        // Create a preview of transformed data
        oss << "Preview: \n";
        for (size_t i = 0; i < buffer.size() && i < 5; ++i)
        {
            oss << "  " << buffer[i] << "\n";
        }

        result.reportLines.push_back(oss.str());

        // Bad design: embedding summary text creation in two forms
        std::string compact = "Summary:[" +
                              std::to_string(result.summary.lines) + "|" +
                              std::to_string(result.summary.errors) + "|" +
                              std::to_string(result.summary.warnings) + "]";
        result.reportLines.push_back(compact);

        // More ad-hoc output
        if (result.summary.warnings > GLOBAL_WARNING_THRESHOLD)
        {
            result.reportLines.push_back("Warning threshold exceeded.");
        }
    }
};

// Simple demonstration test-like main
int main()
{
    DataProcessor p;
    ProcessingResult r = p.run("missing_file.txt");

    std::cout << "Lines: " << r.summary.lines << "\n";
    std::cout << "Errors: " << r.summary.errors << "\n";
    std::cout << "Warnings: " << r.summary.warnings << "\n";
    std::cout << "Transformed: " << r.summary.transformed << "\n";

    return 0;
}

