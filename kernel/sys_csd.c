#include<linux/kernel.h>
#include<linux/syscalls.h>
#define OSL_INITIALIZE_BUCKET 15

struct logical_addr
{
	int addr;
	int add_type;
	int len;
};

struct physical_addr
{
	int pagenum;
	int pagestart;
};

void osl_dev_blockerase(struct physical_addr phyaddr)
{
printk("Succesfully Reached at osl_dev_blockerase\n");
printk("In Osl_dev_blockerase the value of addr = %d \n",phyaddr.addr)
}

//335
SYSCALL_DEFINE1(csd, const char __user*, u_bucketID,int, c_ID) {

	char k_bucketID[256];
	int commandID;
	
	struct physical_addr phyaddr;
	struct ligical_addr logicaddr;
	
	phyaddr.addr =10;
	
	printk("Logging from osl_dev_blockerase!!\n");

	if(!strncpy_from_user(k_bucketID, u_bucketID, 255)) {
		printk("Error resolving parameters\n");
		return -1;  
	}

	printk("Bucket-> %s created.\n", k_bucketID);
	
	commandID=c_ID;
	
	switch(commandID)
	{
		case OSL_INITIALIZE_BUCKET:
		osl_dev_blockerase(phyaddr);break;
		default:
		printk("default function executed");
	}
	return 0;
}

/*336
SYSCALL_DEFINE0(osl_externalinterface) {

	printk("Logging into osl_externalinterface!!\n");

	return 0;
};*/
