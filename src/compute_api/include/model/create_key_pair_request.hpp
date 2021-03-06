/*****************************************************************************
* Copyright (c) 2016 Jiocloud.com, Inc. or its affiliates.  All Rights Reserved
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish, dis-
* tribute, sublicense, and/or sell copies of the Software, and to permit
* persons to whom the Software is furnished to do so, subject to the fol-
* lowing conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABIL-
* ITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
* SHALL THE AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
******************************************************************************/
#ifndef CREATE_KEY_PAIR_H
#define CREATE_KEY_PAIR_H
#include <vector>
#include <string>

using namespace std;
namespace model
{	/// Class to handle create key pair request
	/**
		This class manages the request for create key pair. User can create an object and and initialize the needed arguments.
	*/
	class create_key_pair_request
	{
	private:
		string key_name;

	public:
		/// Constructor
		create_key_pair_request(){}
		/// Getter for the private variable key_name
		/**
			\return const string
		*/ 
		const string get_key_name() const;
		/// Setter for the private variable key_name
		/**
			\param key_name_ : key name of the key pair created (unique for each key pair)
		*/ 
		void set_key_name(const string& key_name_);
	};
}
#endif

