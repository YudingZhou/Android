#include "../includes/common_include.hpp"

using namespace std;

void sequential_vector()
{
    i("sequential containers");
    vector<int> v = {1, 2, 3};
    // append
    v.push_back(4);
    // insert at index
    v.insert(v.begin() + 3, 5);
    // length
    v.size();
    // subview
    v.at(1);
    v.front();
    v.back();
    // get sub vector
    vector<int> v2 = {v.begin(), v.end() - 1};

    // invalidation
    vector<int> v3;
    v3.reserve(1);
    v.push_back(1);
    int &i = v3[0];  // reference to element in v3
    v3.push_back(2); // now the v3 will be resized because adding operation resizes the vector which invalidates all iterator and element references
    cout << "now the v3 will be resized because adding operation resizes the vector which invalidates all iterator and element references" << endl;
    cout << "i =" << i << endl; // FIXME: i is invalidated, this is undefined behavior
}

void sequential_deque()
{
    i("sequential deque");
    deque<int> d = {1, 2, 3};

    d.push_front(0);
    d.push_back(4);
    ostringstream oss;
    for (auto i : d)
    {
        oss << i << ",";
    }
    i(oss.str());
    // to_string is only for numeric conversion
    //  osstringstream is for customized objects
}

void algorithm_with_iterator()
{
    i("algorithm_with_iterator");
    map<int, string> m;
    m[1] = "Yuding";
    m[2] = "Johnny";
    // c++20 m.contains(3)
    // c++11
    if (m.find(3) == m.end())
    {
        cout << "m does not contain 3" << endl;
        m[3] = "no body";
    }

    // get iterator pointer
    auto begin = m.begin();
    auto end = m.end();

    // iterator operation
    cout << "current iterator at " << begin->first << endl;
    advance(begin, 1);

    cout << "after advance 1 iterator at " << begin->first << endl;

    cout << "iterator over" << endl;

    // moving forward
    begin = m.begin();
    while (begin != m.end())
    {
        cout << "iterator at " << begin->first << endl;
        begin = std::next(begin);
    }

    cout << "moving backwards" << endl;
    end = m.end();
    while (end != m.begin())
    {
        // end is not pointing to the last element, need to move prev before access the end
        end = std::prev(end);
        cout << "iterator at " << end->first << endl;
    }
    // algorithm works with iterator

    begin = m.begin();
    end = m.end();

    // when pass distance(end, begin) it causes infinit loop //FIXME
    auto dis = std::distance(begin, end);
    cout << "distance : " << dis << endl;

    i("algo - find");

    i("algo - count");

    i("algo - accumulate");

    // lambda binaryOp
    auto add = [](string a, string b)
    {
        return a + b;
    };

    // compiler is not supporting this
    //  auto sum = std::reduce(m.begin(), m.end(), "", add);

    // cout << "reduced sum " << sum << endl;
    // using std::fill to file the map m
}

void ready_and_write_file()
{
    i("write to output.txt");
    std::ofstream ofs("output.txt", std::ios::binary);
    if (!ofs.is_open())
    {
        ofs.open("output.txt", std::ios::binary);
    }

    ofs << "this is the first line\n";
    ofs << "this is the second line \n";

    ofs.close();

    std::ifstream ifs("output.txt", std::ios::binary);

    if (!ifs.is_open())
    {
        cout << "error" << endl;
    }
    else
    {
        string line;
        // this get token split by whitespace
        // while(ifs >> line){
        //     cout << "current line :" << line << endl;
        // }

        while (std::getline(ifs, line))
        {
            cout << "current line :" << line << endl;
        }
        ifs.close();
    }
}

int main()
{
    sequential_vector();
    sequential_deque();
    algorithm_with_iterator();
    ready_and_write_file();
    return 0;
}