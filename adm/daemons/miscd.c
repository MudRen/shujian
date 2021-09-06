
#define WORKER_FILE	DATA_DIR + "career/"
#define CAN_SAVE_ITEM 30
#define CAN_SAVE_ITEM_VIP 50
#define CAN_SAVE_DAY 100

inherit F_SAVE;

int get_save_num(object me);
void load_save_item(object me);
mapping query_show_list(object me,int reload);
mixed public_do(object ob,mapping row);

void create()
{
	seteuid(getuid());
}

nosave string nowid = "";
nosave string *Save_Settings = ({
"name","id","weight",
});
mapping save_list;
mapping show_list;

int get_save_num(object me)
{
	//for VIP
	if(!me) return 0;
	if(me->query("registered")==3) return CAN_SAVE_ITEM_VIP;
	return CAN_SAVE_ITEM;
}
int get_days()
{
	return CAN_SAVE_DAY;
}

string query_save_file()
{
	if(nowid=="") return 0;	
	return sprintf(WORKER_FILE"%c/%s", nowid[0], nowid);
}

void delete_user_item(object me,string id,string str)
{
	if(!me || !id || !str) return;
	load_save_item(me);
	map_delete(save_list,id);
	save();
	load_save_item(me);	
	call_out("delay_remind",1,me,"�㱣���ĳЩ��Ʒ��Ϊ"+str+"����ϵͳɾ���ˡ�\n");
}

void load_save_item(object me)
{
	string lastid;
	int* ve;
	int i,savetime;
	int change = 0;
	
	lastid = nowid;
	nowid = getuid(me);
	//if(lastid=="" || sprintf("%c",lastid[0]) != sprintf("%c",nowid[0]))
	if(lastid!=nowid)
	{
		save_list =([]);
		show_list =([]);
		restore();
	}
	if (!mapp(save_list)) save_list =([]);
	if (!mapp(show_list)) show_list =([]);
		
	if(!undefinedp(show_list[nowid]))
	{
		ve = keys(show_list[nowid]);
		if(sizeof(ve)<=0) return;
		//����
		for(i=0;i<sizeof(ve);i++)
			if(undefinedp(save_list[show_list[nowid][ve[i]]["save_id"]])){
				//add log here
				//write(sprintf("ɾ��....%s.....show_list %d because can not find %s .. done \n",nowid,ve[i],show_list[nowid][ve[i]]["save_id"],));
				map_delete(show_list[nowid],ve[i]);
				change=1;				
			}
		//��ʱ����Ʒ��delete
		ve = keys(show_list[nowid]);
		if(change!=0){
			if(sizeof(ve)<=0){
				map_delete(show_list,nowid);
				save();				
				return;
			}		
		}
		for(i=0;i<sizeof(ve);i++){
			sscanf(show_list[nowid][ve[i]]["save_id"],"%*s%ds",savetime);
			savetime = time()-savetime;
			if(savetime>CAN_SAVE_DAY*24*60*60)
			{
				//add log here
				call_out("delay_remind",1,me,sprintf("�㱣���%s��Ϊʱ��̫�ñ�ϵͳɾ���ˡ�\n",show_list[nowid][ve[i]]["name"]));
				map_delete(save_list,show_list[nowid][ve[i]]["save_id"]);
				map_delete(show_list[nowid],ve[i]);				
				change=1;
			}
		}
		if(change!=0){
			if(sizeof(keys(show_list[nowid]))<=0) map_delete(show_list,nowid);
			save();
		}
	}
}
int save_this_object(object me,object ob)
{
	string work_save_id,name,id,file;
	mapping temp,tmp;
	int i;
	int value;
		
	load_save_item(me);
	
	work_save_id = sprintf("%s%ds",nowid,time());
	if(!undefinedp(save_list[work_save_id])){
		//add log here
		return 0;
	}
		
	temp = public_do(ob,0);
	if(!mapp(temp)) return 0;
	file = file_name(ob);
	sscanf(file,"%s#%*d",file);
	
	temp["name"] = ob->query("name");
	temp["id"]   = ob->parse_command_id_list();
	temp["weight"]=ob->query_weight();	
	temp["file"] = file;
	
	save_list[work_save_id] = temp;	
	////////////////////for show_list
	name = ob->query("name");
	id = ob->query("id");
	value = ob->query("value");
	temp = copy(query_show_list(me,0));
	i = 1;
	while(!undefinedp(temp[i])){
		i++;
	}	
	tmp = allocate_mapping(get_save_num(me));
	tmp["save_id"] = work_save_id;
	tmp["name"]         = name;
	tmp["id"]           = id;
	tmp["value"]        = value;	
	temp[i]=copy(tmp);
	show_list[nowid] = copy(temp);
			
	if (save()) return 1;
	return 0;
}
mapping query_show_list(object me,int reload)
{	
	if(reload==1) load_save_item(me);
	if(!mapp(show_list) || undefinedp(show_list[nowid])) return ([]);
	return show_list[nowid];
}
mapping query_list()
{
	return show_list;
}

object load_this_object(object me,string save_id,int num)
{	
	mapping temp;
	object ob;
	
	load_save_item(me);
	if(undefinedp(save_list[save_id])){
		//add log here		
		return 0;
	}
	temp = copy(save_list[save_id]);
	ob = new(temp["file"]);
	//add log here
	ob = public_do(ob,temp);
	ob->set_name(temp["name"],temp["id"]);
	ob->set_weight(temp["weight"]);
	temp = query_show_list(me,0);
	map_delete(save_list,save_id);
	map_delete(temp,num);
	show_list[nowid]=temp;
	if(sizeof(keys(temp))==0) map_delete(show_list,nowid);
	save();
	if(objectp(ob)) return ob;		
	return 0;
}

mixed public_do(object ob,mapping row)
{
	mapping out=([]);
	mapping inn=([]);	
	int i;
	string *veb;
	
	if(!objectp(ob)) return 0;	
	inn = ob->query_entire_dbase();
	inn["save_temp_data"] = ob->query_entire_temp_dbase();
	if(mapp(row)) inn = row;	
	veb = keys(inn);
	for(i=0;i<sizeof(veb);i++)
	{	
		if(member_array(veb[i],Save_Settings)==-1)
			if(!undefinedp(inn[veb[i]]) && inn[veb[i]]!=0)
				out[veb[i]] = inn[veb[i]];
	}	
	if(mapp(row))
	{		
		ob->set_entire_temp_dbase(out["save_temp_data"]);
		map_delete(out,"save_temp_data");
		ob->set_entire_dbase(out);		
		return ob;
	}
	return out;
}

void debuging()
{
	//int i = 0;
	//string *ve;
	
	load_save_item(this_player());
	
	write(sprintf("save = %O\n",save_list));
	write(sprintf("show = %O\n",show_list));
	/*
	ve = keys(save_list);
	for(i=0;i<sizeof(ve);i++) write(sprintf("%s   ",ve[i]));
	write("\n");
	ve = keys(query_show_list(this_player()));
	//write("\n");
	for(i=0;i<sizeof(ve);i++) 
		write(sprintf("%d   %s",(int)ve[i],query_show_list(this_player())[ve[i]]["save_id"]));
	write("\n");
	*/
}

void delay_channel(string channel, string arg)
{
	CHANNEL_D->do_channel(this_object(), channel, arg);
}

void delay_remind(object ob, string arg)
{
	if (ob) tell_object(ob, arg);
}
