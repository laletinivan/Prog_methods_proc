#pragma once

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "CppUnitTest.h"
//#include "..\PP\container_atd.h"
//#include "..\PP\plant_atd.h"
//#include "..\PP\tree_atd.h"
#include "../container.cpp"
#include "../plant.cpp"
#include "../tree.cpp"
#include "../flower.cpp"
#include "../bush.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace plants;
using namespace std;

namespace PPUnitTest
{
	TEST_CLASS(PPUnitTest)
	{
	public:

		TEST_METHOD(tree_io)
		{
            ifstream ifst("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\tree_io\\input_tree.txt");
            if (!ifst.is_open())
            {
                Logger::WriteMessage("input file is not open!");
            }
            ofstream ofst("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\tree_io\\output_tree.txt");
            if (!ofst.is_open())
            {
                Logger::WriteMessage("output file is not open!");
            }

            tree* t = in_tree(ifst);
            out(*t, ofst);
            ifst.close();
            ofst.close();

            string one, two, tmp;

            ifstream ifst1("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\tree_io\\example_tree.txt");
            ifstream ifst2("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\tree_io\\output_tree.txt");

            while (!ifst1.eof()) 
            {
                getline(ifst1, tmp);
                one += tmp;
            }

            while (!ifst2.eof()) 
            {
                getline(ifst2, tmp);
                two += tmp;
            }

            Assert::AreEqual(one, two);
            
            ifst1.close();
            ifst2.close();
		}
		TEST_METHOD(bush_io)
		{
            ifstream ifst("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\bush_io\\input_bush.txt");
            if (!ifst.is_open())
            {
                Logger::WriteMessage("input file is not open!");
            }
            ofstream ofst("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\bush_io\\output_bush.txt");
            if (!ofst.is_open())
            {
                Logger::WriteMessage("output file is not open!");
            }

            bush* t = in_bush(ifst);
            out(*t, ofst);
            ifst.close();
            ofst.close();

            string one, two, tmp;

            ifstream ifst1("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\bush_io\\example_bush.txt");
            ifstream ifst2("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\bush_io\\output_bush.txt");

            while (!ifst1.eof()) 
            {
                getline(ifst1, tmp);
                one += tmp;
            }

            while (!ifst2.eof())
            {
                getline(ifst2, tmp);
                two += tmp;
            }

            Assert::AreEqual(one, two);

            ifst1.close();
            ifst2.close();
		}
        TEST_METHOD(flower_io)
        {
            ifstream ifst("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\flower_io\\input_flower.txt");
            if (!ifst.is_open())
            {
                Logger::WriteMessage("input file is not open!");
            }
            ofstream ofst("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\flower_io\\output_flower.txt");
            if (!ofst.is_open())
            {
                Logger::WriteMessage("output file is not open!");
            }

            flower* t = in_flower(ifst);
            out(*t, ofst);
            ifst.close();
            ofst.close();

            string one, two, tmp;

            ifstream ifst1("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\flower_io\\example_flower.txt");
            ifstream ifst2("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\flower_io\\output_flower.txt");

            while (!ifst1.eof())
            {
                getline(ifst1, tmp);
                one += tmp;
            }

            while (!ifst2.eof())
            {
                getline(ifst2, tmp);
                two += tmp;
            }

            Assert::AreEqual(one, two);

            ifst1.close();
            ifst2.close();
        }
        TEST_METHOD(plant_io)
        {
            ifstream ifst1("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\input_bush.txt");
            ifstream ifst2("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\input_flower.txt");
            ifstream ifst3("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\input_tree.txt");
            if (!ifst1.is_open() || !ifst2.is_open() || !ifst3.is_open())
            {
                Logger::WriteMessage("input files are not open!");
            }

            ofstream ofst1("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\output_bush.txt");
            ofstream ofst2("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\output_flower.txt");
            ofstream ofst3("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\output_tree.txt");
            if (!ofst1.is_open() || !ofst2.is_open() || !ofst3.is_open())
            {
                Logger::WriteMessage("output files are not open!");
            }

            plant* p1 = in_plant(ifst1);
            plant* p2 = in_plant(ifst2);
            plant* p3 = in_plant(ifst3);
            out(*p1, ofst1);
            out(*p2, ofst2);
            out(*p3, ofst3);
            ifst1.close();
            ifst2.close();
            ifst3.close();
            ofst1.close();
            ofst2.close();
            ofst3.close();

            ifstream if1("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\output_bush.txt");
            ifstream if2("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\output_flower.txt");
            ifstream if3("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\output_tree.txt");

            string s1, s2, s3, s4, s5, s6, tmp;

            ifstream if4("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\example_bush.txt");
            ifstream if5("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\example_flower.txt");
            ifstream if6("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_io\\plant_io\\example_tree.txt");

            while (!if1.eof()) 
            {
                getline(if1, tmp);
                s1 += tmp;
            }
            while (!if2.eof()) 
            {
                getline(if2, tmp);
                s2 += tmp;
            }
            while (!if3.eof())
            {
                getline(if3, tmp);
                s3 += tmp;
            }
            while (!if4.eof())
            {
                getline(if4, tmp);
                s4 += tmp;
            }
            while (!if5.eof())
            {
                getline(if5, tmp);
                s5 += tmp;
            }
            while (!if6.eof())
            {
                getline(if6, tmp);
                s6 += tmp;
            }

            Assert::AreEqual(s1, s4);
            Assert::AreEqual(s2, s5);
            Assert::AreEqual(s3, s6);

            if1.close();
            if2.close();
            if3.close();
            if4.close();
            if5.close();
            if6.close();
        }
        TEST_METHOD(cons)
        {
            plant p;
            
            p.name = "dub";
            Assert::AreEqual(Consanants(p), 2);
            p.name = "db";
            Assert::AreEqual(Consanants(p), 2);
            p.name = "aaa";
            Assert::AreEqual(Consanants(p), 0);
            p.name = "kust";
            Assert::AreEqual(Consanants(p), 3);
            p.name = "kkust";
            Assert::AreEqual(Consanants(p), 4);
            p.name = "uuu";
            Assert::AreEqual(Consanants(p), 0);

        }
        TEST_METHOD(plant_cmp)
        {
            plant p1 , p2;

            p1.cons = 1;
            p2.cons = 2;
            Assert::AreEqual(compare(p1,p2), true);
            p1.cons = 2;
            p2.cons = 1;
            Assert::AreEqual(compare(p1, p2), false);
            p1.cons = 0;
            p2.cons = 0;
            Assert::AreEqual(compare(p1, p2), false);
            p1.cons = -2;
            p2.cons = 2;
            Assert::AreEqual(compare(p1, p2), true);

        }
        TEST_METHOD(only_bush_out)
        {
            ifstream ifst("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_only_bush_out\\only_bush_input.txt");
            if (!ifst.is_open())
            {
                Logger::WriteMessage("input file is not open!");
            }
            ofstream ofst("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_only_bush_out\\only_bush_output.txt");
            if (!ofst.is_open())
            {
                Logger::WriteMessage("output file is not open!");
            }

            container c;
            init(c);
            in(c, ifst);
            out_bush(c, ofst);
            ifst.close();
            ofst.close();

            string one, two, tmp;

            ifstream ifst1("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_only_bush_out\\only_bush_example.txt");
            ifstream ifst2("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_only_bush_out\\only_bush_output.txt");

            while (!ifst1.eof())
            {
                getline(ifst1, tmp);
                one += tmp;
            }

            while (!ifst2.eof()) 
            {
                getline(ifst2, tmp);
                two += tmp;
            }

            Assert::AreEqual(one, two);

            ifst1.close();
            ifst2.close();
        }
        TEST_METHOD(container_sort)
        {
            ifstream ifst("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_sort\\sort_input.txt");
            if (!ifst.is_open())
            {
                Logger::WriteMessage("input file is not open!");
            }
            ofstream ofst("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_sort\\sort_output.txt");
            if (!ofst.is_open())
            {
                Logger::WriteMessage("output file is not open!");
            }

            container c;
            init(c);
            in(c, ifst);
            sort(c);
            out(c, ofst);
            ifst.close();
            ofst.close();

            string one, two, tmp;

            ifstream ifst1("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_sort\\sort_example.txt");
            ifstream ifst2("D:\\VS2019projects\\PP\\PPUnitTest\\test\\test_sort\\sort_output.txt");

            while (!ifst1.eof()) 
            {
                getline(ifst1, tmp);
                one += tmp;
            }

            while (!ifst2.eof())
            {
                getline(ifst2, tmp);
                two += tmp;
            }

            Assert::AreEqual(one, two);

            ifst1.close();
            ifst2.close();
        }
        TEST_METHOD(push_del_elem)
        {
            container c;
            elem* e1 = new elem;
            elem* e2 = new elem;
            elem* e3 = new elem;
            init(c);
            push(c, e1);

            string head, tail, tmp;
            ostringstream oss;

            oss << e1;
            tmp = oss.str();

            oss.str("");
            oss << c.head;
            head = oss.str();

            oss.str("");
            oss << c.tail;
            tail = oss.str();

            Assert::AreEqual(c.size, 1);
            Assert::AreEqual(tmp, head);
            Assert::AreEqual(tmp, tail);

            push(c, e2);

            Assert::AreEqual(c.size, 2);
            Assert::AreEqual(tmp, head);

            oss.str("");
            oss << e2;
            tmp = oss.str();

            oss.str("");
            oss << c.tail;
            tail = oss.str();

            Assert::AreEqual(tmp, tail);

            push(c, e3);

            Assert::AreEqual(c.size, 3);

            delete_at(c, 0);

            Assert::AreEqual(c.size, 2);

            oss.str("");
            oss << c.head;
            head = oss.str();

            Assert::AreEqual(tmp, head);

            delete_at(c, 3);

            Assert::AreEqual(c.size, 2);

            delete_at(c, 1);

            Assert::AreEqual(c.size, 1);

            oss.str("");
            oss << c.tail;
            tail = oss.str();

            Assert::AreEqual(tmp, tail);
        }
	};
}
