#include "stdafx.h"
#include <direct.h>
#include "TemporaryFolder.h"
#include "../Dictionary/Dictionary.h"


BOOST_AUTO_TEST_SUITE(Dictionary_class)

	CTemporaryFolder temp;
	BOOST_AUTO_TEST_SUITE(when_work_with_dictionary_file)


		BOOST_AUTO_TEST_CASE(read_translations_from_it)
		{
			CDictionary dict("testDict.txt");
			BOOST_CHECK(!dict.GetTranslation("father").empty());
			BOOST_CHECK(dict.GetTranslation("папа").empty());
		}

		BOOST_AUTO_TEST_CASE(can_add_new_word_and_save_changes_into_dict_file)
		{
			CDictionary dict("testDict.txt");
			std::string word = "The hateful eight";
			std::string trans = "омерзительная восьмерка";
			BOOST_CHECK(dict.GetTranslation(word).empty());
			dict.AddWord(word, trans);
			BOOST_CHECK(dict.GetTranslation(word) == trans);

			dict.SaveChanges();
			CDictionary dictWithNewWords("testDict.txt");
			BOOST_CHECK(!dict.GetTranslation(word).empty());
			dict.DeleteWord(word);
			dict.SaveChanges();
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(when_work_without_dictionary_file)


		BOOST_AUTO_TEST_CASE(can_add_new_word_and_save_changes_into_new_dict_file)
		{
			CDictionary dict(temp.GetPath() + "nothing.txt");
			std::string word = "The hateful eight";
			std::string trans = "омерзительная восьмерка";
			BOOST_CHECK(dict.GetTranslation(word).empty());
			dict.AddWord(word, trans);
			BOOST_CHECK(dict.GetTranslation(word) == trans);

			dict.SaveChanges();
			CDictionary ndict(temp.GetPath() + "nothing.txt");
			BOOST_CHECK(!dict.GetTranslation(word).empty());
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()