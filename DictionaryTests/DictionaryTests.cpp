#include "stdafx.h"
#include <direct.h>
#include "TemporaryFile.h"
#include "../Dictionary/Dictionary.h"

BOOST_AUTO_TEST_SUITE(Dictionary_class)

	BOOST_AUTO_TEST_SUITE(when_work_with_dictionary_file)

		CDictionary dict("testDict.txt");

		BOOST_AUTO_TEST_CASE(read_translations_from_it)
		{
			BOOST_CHECK(dict.IsWordInDict("father"));
			BOOST_CHECK(!dict.IsWordInDict("папа"));
		}

		BOOST_AUTO_TEST_CASE(can_add_new_word_and_save_changes_into_dict_file)
		{
			std::string word = "The hateful eight";
			std::string trans = "омерзительная восьмерка";
			BOOST_CHECK(!dict.IsWordInDict(word));
			dict.AddWord(word, trans);
			BOOST_CHECK(dict.IsWordInDict(word));
			BOOST_CHECK(dict.GetTranslation(word) == trans);

			dict.SaveChanges();
			CDictionary dict("testDict.txt");
			BOOST_CHECK(dict.IsWordInDict(word));
			dict.DeleteWord(word);
			dict.SaveChanges();
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(when_work_without_dictionary_file)

		CDictionary dict("nothing.txt");
		CTemporaryFile temp("nothing.txt");

		BOOST_AUTO_TEST_CASE(can_add_new_word_and_save_changes_into_new_dict_file)
		{
			std::string word = "The hateful eight";
			std::string trans = "омерзительная восьмерка";
			BOOST_CHECK(!dict.IsWordInDict(word));
			dict.AddWord(word, trans);
			BOOST_CHECK(dict.IsWordInDict(word));
			BOOST_CHECK(dict.GetTranslation(word) == trans);

			dict.SaveChanges();
			CDictionary dict("nothing.txt");
			BOOST_CHECK(dict.IsWordInDict(word));
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()