// Creat by Ciwei@SJ

inherit EQUIP;
#include "/d/zhiye/obj/material.h"

void initlvl();

void create()
{
       
        set_name(HIW "���ʯ" NOR, ({ "ciwei shi","shi"}));         
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("value", 5000000);              
		set("long", "����ɿڣ���Ծͳԣ�\n");
		set("material", "stone");		
		set("can_dazao",1);	
		set("unit","��");			
		}
	setup();
	initlvl();
}

int query_level()
{
        return query("level");
}
int set_level(int level,int hehe)
{
	string type;
	mapping get;
	
	if(hehe==1) type="weapon";
	else if(hehe==2) type="armor";
	else type=random(2)?"weapon":"armor";
	if(level<1 || level>6) return 0;
	get = essence[type][level-1];
	if(!mapp(get))
	{
                message("wizard:server","error at othermaterial no mapping static\n",users());
	 	return 0;
	}
	
	set("level",level);	
	set_weight(get["weight"]);
	set("long",get["long"]);	
	//set("long2",get["long"]);
	set("unit",get["unit"]);
	set("material_level",get["level"]);
	set("material_for",type);
	set("material_status",get["status"][0]+random(get["status"][1]));
	set("value",get["value"][0]+random(get["value"][1]));
	if(arrayp(get["damage"])) set("material_prop/damage",get["damage"][0]+random(get["damage"][1]));
	if(arrayp(get["armor"])) set("material_prop/armor",get["armor"][0]+random(get["armor"][1]));
		
	if(random(20)==1){
		set_name(get["name"],get["id"]);
		WORKER_D->get_status(this_object(),3,query("material_status"),1,type);
		}
	else {
	set_name(get["name"]+NOR,get["id"]);
		WORKER_D->get_status(this_object(),3,query("material_status"),0,type);
	}
	if(type=="weapon"){
		delete("material_prop/armor");
		delete("material_prop/defense");
	}
	if(type=="armor"){
		delete("material_prop/damage");
		delete("material_prop/attack");
	}	
	//msg = WORKER_D->get_msg(query("material_prop"));
	//if(stringp(msg) && msg!="") set_temp("apply/long",({short()+"\n"+query("long")+msg }));	
	return 1;
}

void initlvl()
{
	if(clonep()) call_out("delete_owner",90+random(30));
}
