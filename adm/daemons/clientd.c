// clientd.c
// by augx@sj 12/13/2001

#include <client.h>

#define DEBUG_MODE	0


int IsClient(object ob)
{
	return ( ob->query_temp("client_type") == SJCLIENT ); 	
}

int ObjectType(object ob)
{
	if( !ob->is_character() || ob->is_corpse() )
		return 0;
	else if ( !userp(ob) )
		return 1;
	else 
		return 2;
}

void SendClientInfo(object ob,int type,string info)
{
	int i,l,len = strlen(info);
	string head = "abcd";
	
	if( len > CLIENT_TOTAL_BYTES ) {
		len = CLIENT_TOTAL_BYTES;
		info[len] = 0;
	}
	l = 0;
	for(i=0;i<len;i++)
		if( info[i] == '\n' ) l++;
	len += l;
	
	head[0] = CLIENT_FLAG1;
	head[1] = CLIENT_FLAG2 + (int)( len / CLIENT_LOWBYTE );
	head[2] = CLIENT_LOWBYTE_BASE + ( len % CLIENT_LOWBYTE );
	head[3] = type;
	tell_object(ob,head+info);
	
	if(DEBUG_MODE) tell_object(ob,"[CLIENTD]: "+info+"\n");
}

void CheckStateChange(object ob)
{
	int max_food , max_water;
	mapping my , myt;
	
	if ( ob->query_temp("client_type") != SJCLIENT ) return;
	
	my = ob->query_entire_dbase();
	myt = ob->query_entire_temp_dbase();
	
	if( my["jing"] != myt["client/jing"]
	 || my["eff_jing"] != myt["client/eff_jing"]
	 || my["max_jing"] != myt["client/max_jing"] 
	 || myt["apply/jing"] != myt["client/apply_jing"]
	 
	 || my["qi"] != myt["client/qi"]
	 || my["eff_qi"] != myt["client/eff_qi"]
	 || my["max_qi"] != myt["client/max_qi"]
	 || myt["apply/qi"] != myt["client/apply_qi"]
		 
	 || my["jingli"] != myt["client/jingli"]
	 || my["eff_jingli"] != myt["client/eff_jingli"]
	 || myt["apply/jingli"] != myt["client/apply_jingli"]
		 
	 || my["neili"] != myt["client/neili"]
	 || my["max_neili"] != myt["client/max_neili"]
	 || myt["apply/neili"] != myt["client/apply_neili"]
	) {
		myt["client/jing"] = my["jing"];
		myt["client/eff_jing"] = my["eff_jing"];
		myt["client/max_jing"] = my["max_jing"];
		myt["client/apply_jing"] = myt["apply/jing"];
		
		myt["client/qi"] = my["qi"];
		myt["client/eff_qi"] = my["eff_qi"];
		myt["client/max_qi"] = my["max_qi"];
		myt["client/apply_qi"] = myt["apply/qi"];
		
		myt["client/jingli"] = my["jingli"];
		myt["client/eff_jingli"] = my["eff_jingli"];
		myt["client/apply_jingli"] = myt["apply/jingli"];
		
		myt["client/neili"] = my["neili"];
		myt["client/max_neili"] = my["max_neili"];
		myt["client/apply_neili"] = myt["apply/neili"];
				
		SendClientInfo(ob , CLIENT_QI , sprintf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d",
			my["jing"],my["eff_jing"],my["max_jing"],myt["apply/jing"],
			my["qi"],my["eff_qi"],my["max_qi"],myt["apply/qi"],
			my["jingli"],my["eff_jingli"],myt["apply/jingli"],
			my["neili"],my["max_neili"],myt["apply/neili"] ));
	}
		
	if( my["potential"] != myt["client/potential"] 
	 || my["max_pot"] != myt["client/max_pot"]
	 || my["combat_exp"] != myt["client/combat_exp"] 
	) {
		myt["client/combat_exp"] = my["combat_exp"];
		myt["client/potential"] = my["potential"];
		myt["client/max_pot"] = my["max_pot"];
		
		SendClientInfo(ob , CLIENT_EXP , sprintf("%d %d %d",
			my["potential"],my["max_pot"],my["combat_exp"] ));
	}
		
	max_food = ob->max_food_capacity();
	max_water = ob->max_water_capacity();
		
	if( my["food"] != myt["client/food"]
	 || max_food != myt["client/max_food"]
	 || my["water"] != myt["client/water"]
	 || max_water != myt["client/max_water"]
	 || my["shen"] != myt["client/shen"] 
	) {
	 	myt["client/food"] = my["food"];
	 	myt["client/max_food"] = max_food;
	 	myt["client/water"] = my["water"]; 
	 	myt["client/max_water"] = max_water;
	 	myt["client/shen"] = my["shen"];
	 	
		SendClientInfo(ob , CLIENT_FOOD , sprintf("%d %d %d %d %d",
			my["food"],max_food,my["water"],max_water,my["shen"] ));
	}
}

void ChangeInv(object me,object ob,int bIn)
{
	int type = 0;
	if( ob->query("equipped") )
		type = 1;
	else if( ob->query("embedded") )
		type = 2;
		
	SendClientInfo(me , bIn?CLIENT_INV_IN:CLIENT_INV_OUT , 
		ob->query("base_unit") ? 
		sprintf("%d %d %s%s %s",type,ob->query_amount(),ob->query("base_unit"),ob->name(),ob->query("id")) : 
		sprintf("%d 0 %s %s",type,ob->name(),ob->query("id")) );
}

void ChangeInvSet(object me,object ob)
{
	int type = 0;
	if( ob->query("equipped") )
		type = 1;
	else if( ob->query("embedded") )
		type = 2;
		
	SendClientInfo(me , CLIENT_INV_SET , 
		sprintf("%d %d %s%s %s",type,ob->query_amount(),ob->query("base_unit"),ob->name(),ob->query("id")) );
}

void ChangeRoom(object me,object room)
{
	object * inv;
	string str;
	string * dirs;
	string clone_number;
	int i;
	
	str = "";
	inv = all_inventory(room);
	foreach(object item in inv) {
		if(item==me) continue;
		if(!me->visible(item)) continue;
		if( sscanf(file_name(item),"%*s#%s",clone_number) < 2 )
			clone_number = file_name(item);
		str += sprintf("%d %s %s,",ObjectType(item),clone_number,item->short());
	}
	if( strlen(str) > 0 )
		str[strlen(str)-1] = '|';
	else
		str = "|";
	
	if( mapp(room->query("exits")) ) {
		dirs = keys(room->query("exits"));
		for(i=0;i<sizeof(dirs);i++)
			str += (dirs[i] + " ");
	}

	SendClientInfo(me , CLIENT_ROOM , str);
}

void ChangeRoomObj(object room,object ob,int bIn)
{
	object * inv;
	string clone_number;
	
	if(!clonep(ob)) return;
	if( sscanf(file_name(ob),"%*s#%s",clone_number) < 2 )
		clone_number = file_name(ob);
	
	inv = all_inventory(room);
	foreach(object me in inv) {	
		if(userp(me) && me!=ob && IsClient(me)) {
			SendClientInfo(me , bIn?CLIENT_ROOMOBJ_IN:CLIENT_ROOMOBJ_OUT ,
				sprintf("%d %s %s",ObjectType(ob),clone_number,ob->short()) );
		}
	}
}

void SendRoomLong(object me,string str)
{
	SendClientInfo(me, CLIENT_ROOM_LONG, str);
}
