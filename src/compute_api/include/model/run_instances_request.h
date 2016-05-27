#ifndef RUN_INSTANCES_H
#define RUN_INSTANCES_H
#include <vector>
#include <string>
#include "../../../utils.cpp"

using namespace std;
using namespace utils;
namespace model
{	/// Class to handle run instances request
	/**
		This class manages the request for run instances. User can create an object and and initialize the needed arguments.
	*/
	class run_instances_request
	{
	private:
		string image_id;
		string instance_type_id;
		vector<struct utils::block_device_mapping> blocks;
		int instance_count;
		string subnet_id;
		string private_ip_address;
		vector<string> security_group_ids;
		string key_name;

	public:
		/// Constructor
		run_instances_request();
		/// Getter for the private variable image_id
		/**
			\return const string
		*/
		const string get_image_id();
		/// Setter for the private variable image_id
		/**
			\param image_id_ : image id of new instances to be created
		*/
		void set_image_id(string image_id_);
		/// Getter for the private variable inatance_type_id
		/**
			\return const string
		*/
		const string get_instance_type_id();
		/// Setter for the private variable instance_type_id
		/**
			\param instance_type_id_ : instance type id of the new instances to be created
		*/
		void set_instance_type_id(string instance_type_id_);
		/// Getter for the private variable blocks
		/**
			\return vector<block_device_mapping> *
		*/
		const vector<struct utils::block_device_mapping> *get_block_device_mapping();
		/// Setter for the private variable blocks
		/**
			\param blockset (optional): List of settings to be used for volumes being created during
    		instance launch. This itself is a structure which supports the
    		following options.\n
        		DeleteOnTermination\n
        		VolumeSize\n
        		DeviceName\n
        		SnapshotId\n
    		Please refer to the Compute help guide for more information on
		    how to work with these parameters.
		    If not specified, JCS takes the boot volume information from the
		    OS image properties.		*/
		void set_block_device_maping(vector <struct utils::block_device_mapping> block_set);
		/// Getter for the private variable instance_count
		/**
			\return const int
		*/
		const int get_instance_count();
		/// Setter for the private variable instance_count
		/**
			\param instance_count_ (optional): Integer representing how many instances to be launched. Default is 1.
		*/
		void set_instance_count(int instance_count_);
		/// Getter for the private variable subnet_id
		/**
			\return const string
		*/
		const string get_subnet_id();
		/// Setter for the private variable subnet_id
		/**
			\param subnet_id_ (optional): Unique identifier for the subnet where the instance is created.
		    Incase one doesnt provide this value, an appropriate subnet is
		    selected
		*/
		void set_subnet_id(string subnet_id_);
		/// Getter for the private variable private_ip_address
		/**
			\return const string
		*/
		const string get_private_ip_address();
		/// Setter for the private variable private_ip_address
		/**
			\param private_ip_address_ (optional): Valid IP address from the subnet CIDR block. If not given, an
    		available private IP address is selected
		*/
		void set_private_ip_adddress(string private_ip_adddress_);
		/// Getter for the private variable security_group_ids
		/**
			\return vector<string> *
		*/
		const vector<string> *get_security_group_ids();
		/// Getter for the private variable security_group_ids
		/**
			\param security_group_id_set (optional): One or more security groups to be associated to the instance.
		    If not given, default security group is associated with the
		    instance
		*/
		void set_security_group_ids(vector<string> security_group_id_set);
		/// Getter for the private variable key_name
		/**
			\return const string
		*/
		const string get_key_name();
		/// Setter for the private variable key_name
		/**
			\param key_name_ (optional): Key Name to be used while launching the instance. If not given
    		instance can be still launched but not reached
		*/
		void set_key_name(string key_name_);
	};

}
#endif
