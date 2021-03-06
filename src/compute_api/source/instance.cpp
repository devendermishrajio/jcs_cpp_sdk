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
#include "instance.hpp"
#include <openssl/pem.h>
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include "requestify.hpp"
#include <sstream>
#include <map>

namespace instance 
{

	pair<string,long> describe_instances(utils::auth_var &info, const model::describe_instances_request &req)
	{
		map <string, string> params;
		params["Action"] = "DescribeInstances";
		params["Version"] = info.version;
		
		string key = "InstanceId.";
		stringstream ss;	// To convert int to string
		for(size_t i=0 ; i<(req.get_instance_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_ids())[i];
			ss.str("");
		}

		//// TODO : Add filters
		// Right now filters functionality is broken, it works only
	   	// for cases like --filters "Name=abc,Values=def"
		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> describe_instance_types(utils::auth_var &info, const model::describe_instance_types_request &req)
	{
		map <string, string> params;
		params["Action"] = "DescribeInstanceTypes";
		params["Version"] = info.version;
		
		string key = "InstanceTypeId.";
		stringstream ss;
		for(size_t i=0 ; i<(req.get_instance_type_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_type_ids())[i];
			ss.str("");
		}

		//// TODO : Add filters
		// Right now filters functionality is broken, it works only
	   	// for cases like --filters "Name=abc,Values=def"
		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> start_instances(utils::auth_var &info, const model::start_instances_request &req)
	{
		map <string, string> params;
		params["Action"] = "StartInstances";
		params["Version"] = info.version;
		
		if((req.get_instance_ids())->size() == 0)
		{	
			cout << "Error : Instance-Id needed";
		}

		string key = "InstanceId.";
		stringstream ss;
		for(size_t i=0 ; i<(req.get_instance_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_ids())[i];
			ss.str("");
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string,long> stop_instances(utils::auth_var &info, const model::stop_instances_request &req)
	{
		map <string, string> params;
		params["Action"] = "StopInstances";
		params["Version"] = info.version;

		if((req.get_instance_ids())->size() == 0)
		{	
			cout << "Error : Instance-Id needed";
		}

		string key = "InstanceId.";
		stringstream ss;
		for(size_t i=0 ; i<(req.get_instance_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_ids())[i];
			ss.str("");
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> reboot_instances(utils::auth_var &info, const model::reboot_instances_request &req)
	{
		map <string, string> params;
		params["Action"] = "RebootInstances";
		params["Version"] = info.version;
		
		if((req.get_instance_ids())->size()== 0)
		{	
			cout << "Error : Instance-Id needed";
		}

		string key = "InstanceId.";
		stringstream ss;
		for(size_t i=0 ; i<(req.get_instance_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_ids())[i];
			ss.str("");
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}


	pair<string,long> terminate_instances(utils::auth_var &info, const model::terminate_instances_request &req)
	{
		map <string, string> params;
		params["Action"] = "TerminateInstances";
		params["Version"] = info.version;
		
		if((req.get_instance_ids())->size() == 0)
		{	
			cout << "Error : Instance-Id needed";
		}

		string key = "InstanceId.";
		stringstream ss;
		for(size_t i=0 ; i<(req.get_instance_ids())->size() ; i++)
		{
			ss << i+1;
			params[key+ss.str()] = (*req.get_instance_ids())[i];
			ss.str("");
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}



	pair<string,long> run_instances(utils::auth_var &info, const model::run_instances_request &req )
	{
		map <string, string> params;
		params["Action"] = "RunInstances";
		params["Version"] = info.version;

		if(req.get_image_id().length() == 0)
		{	
			cout << "Error : Image-Id needed";
		}
		else
		{
			params["ImageId"] = req.get_image_id();
		}

		if(req.get_instance_type_id().length() == 0)
		{	
			cout << "Error : Instance-Type-Id needed";
		}
		else
		{
			params["InstanceTypeId"] = req.get_instance_type_id();
		}

		if((req.get_block_device_mapping())->size() != 0)
		{
			string key = "BlockDeviceMapping.";
			stringstream ss,ss1;
			for(size_t i=0 ; i<(req.get_block_device_mapping())->size() ; i++)
			{
				ss << i+1;
				params[key+ss.str()+".DeviceName"] = (*req.get_block_device_mapping())[i].device_name;
				(*req.get_block_device_mapping())[i].delete_on_termination ? ss1.str("true") : ss1.str("false");
				params[key+ss.str()+".DeleteOnTermination"] = ss1.str();
				ss1.str("");
				ss1 << (*req.get_block_device_mapping())[i].volume_size;
				params[key+ss.str()+".VolumeSize"] = ss1.str();
				ss1.str("");
				ss.str("");
			}
		}

		if(req.get_instance_count()!=-1)
		{
			params["InstanceCount"] = req.get_instance_count();
		}

		if(req.get_subnet_id()!="")
		{
			params["SubnetId"] = req.get_subnet_id();
		}

		if(req.get_private_ip_address()!="")
		{
			params["PrivateIPAddress"] = req.get_private_ip_address();
		}

		if(!(req.get_security_group_ids())->empty())
		{
			for(size_t i=0 ; i<(req.get_security_group_ids())->size() ; i++)
			{
				string key = "SecurityGroupId.0";
				key[key.length()-1] = i+1;
				params[key] = (*req.get_security_group_ids())[i];
			}		
		}

		if(req.get_key_name()!="")
		{
			params["KeyName"] = req.get_key_name();
		}

		return requestify::make_request(info, params);	// requestify::make_request function in "requestify.cpp"
	}

	pair<string, long> get_password_data(utils::auth_var &info, const model::get_password_data_request &req)

	{	
		map<string , string > params;
		params["Action"] = "GetPasswordData";
		params["Version"] = info.version;

		if(req.get_instance_id().length() == 0){
			cout<<"Instance-ID is Required"<<endl;
		}
		else{
			params["InstanceId"] = req.get_instance_id();
		} 

		return requestify::make_request(info,params);

	}

	string decrypt_password(const char* encrypted_password, const std::string &private_key_file, const std::string& passphrase)
	{
		
		RSA *rsa = utils::import_ssh_key(private_key_file, passphrase);
		int en_len = strlen(encrypted_password);	
		
		//Decode encrypted password data twice
		char password_data[(en_len*6/8)+en_len%8];
		int length;
		length = utils::base64decode(encrypted_password , password_data,en_len );
		length = utils::base64decode(password_data, password_data, length);

		//Rsa Decrypt
		unsigned char to[length];
		int padding = RSA_PKCS1_PADDING;
		int res = RSA_private_decrypt(length,(unsigned char*)password_data,to, rsa, padding);
		if(res!= -1)return (char *)to;
		else 
		{
			printf("Error in RSA decryption of Password Data.\n");
			return "Error";
		}
	}
}
