/*
 * browserSupport.cpp
 *
 *  Created on: Apr 20, 2019
 *      Author: dgv130030
 */

#include "browserSupport.h"

#include <string>




url::operator std::string() const
{
	return text();
}


std::vector<url> *browserSupport::pVector = nullptr;

void browserSupport::buildHistory(const url &nextURL)
{
	if (pVector != nullptr)
	{
		(*pVector).push_back(nextURL);
	}
}

std::size_t browserSupport::history(std::vector<url> &historyURLs)
{
	historyURLs.clear();
	browserSupport::pVector = &historyURLs;

	historyQueue.traverse(&browserSupport::buildHistory);


	browserSupport::pVector = nullptr;

	return 0;
}
