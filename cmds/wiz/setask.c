//setask.c 
//for set ask
// /cmds/wiz/setask.c
// ϣ��cp ��imm�� ��Ȼż��û������ 

#define TONG "/clone/npc/tong"
object get_player(string arg);
object get_tong();
int help(object me);
void update_tong();

int main(object me, string arg)
{
	mapping ask;
	mapping* answer;
	string* top;
	string same = "";
	object tong;
	int i;
	
	if(!arg) return help(me);
	if (wiz_level(me) < 3 && getuid(me)!="ciwei" )
		return notify_fail("ֻ�� wizard �ȼ�������ʦ�ſ���ʹ�ô�ָ�\n");
	if(!objectp(tong = get_tong())) return notify_fail("����ͨ��δ���ơ��޷�ͨѶ��\n");
	ask = tong->query_ask();
	if(sscanf( arg,"delete %s",arg) == 1  )
	{
		if(mapp(ask) && !mapp(ask[arg])) return notify_fail("û�д�ask��\n");
		if( tong->delete_ask(arg))
		{
			write("ɾ��OK��\n");
			update_tong();
			return 1;
		}
		return notify_fail("�޸�ʧ�ܡ�\n");
	}	
	if(mapp(ask) && mapp(ask[arg]) && stringp(ask[arg]["word"]))
	{
		write(ask[arg]["word"]+"\n");
		answer = values(ask);
		top = keys(ask);
		for(i=0;i<sizeof(answer);i++)
		{
			if( answer[i]["word"]==ask[arg]["word"]) same +=","+top[i];
		}
		if(same != "" && same != (","+arg)) write("�������ask��ͬ�ش�"+same+"  �����һ���޸ġ�\n");
		write("ask "+arg+" �������Ѿ����ڣ�Ҫ�滻ô��[Y\\N]\n");
		input_to("config_set",me,arg,tong);
		return 1;
	}
	write("����ش������(����q ȡ��)��\n");
	input_to("get_msg_select", me,arg,tong);
	return 1;
}
void config_set(string get,object me,string arg,object tong)
{
	if( get == "Y" || get =="y" || get[0]=='y' || get[0]=='Y' ) 
	{
		write("����ش�����ݣ�\n");
		input_to("get_msg_select", me,arg,tong);
		return;
	}
	else {
	write("�����޸ġ�\n");
	return;
	}
}
void get_msg_select(string get,object me,string arg,object tong)
{
	mapping def = allocate_mapping(3);
	if(!stringp(get) || get == "Q" || get =="q" || get =="" ) {
	write("�����޸ġ�\n");
	return;
	}
	def["word"]=get;
	def["semote"]="";
	def["updated"]="";
	write("����ش��ִ�е�semote(ֱ�ӻس� ��ʾ�����κ�semote):\n");
	input_to("get_semote_select", me,arg,def,tong);
	return;	
}
void get_semote_select(string get,object me,string arg,mapping def,object tong)
{
	def["semote"]=get;
	def["updated"]=getuid(me);
	if(!stringp(get)) get = "";
	if (!tong->set_ask(arg,def))
	{
	write("�޸�ʧ�ܡ�\n");
	return;
	}
	write("�޸���ɡ�\n");
	update_tong();
	return;	
}
object get_player(string arg)
{
	object user;
	string msg;
	
	user = new(USER_OB);
	seteuid(arg);
	export_uid(user);
	user->set_name("", ({ arg }));
	if (!user->restore())
        { destruct(user); return 0;};
	msg = user->name();
	user->create();
	seteuid("MudOS");
	export_uid(user);
	user->set_name(msg, ({ arg }));
	user->setup();
	return user;
}
object get_tong()
{
	object* obs;
		
	obs = children(TONG);
	if(sizeof(obs)<=0) return 0;
	return obs[0];
}
void update_tong()
{
	object* obs;
	int i;
		
	obs = children(TONG);
	if(sizeof(obs)<=0) return;
	for(i=0;i>sizeof(obs);i++)
	{
		if(objectp(obs[i])) obs[i]->restore();
	}
	return;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��setask xxx

����������������������ͨ�Զ��ش�ġ�

�����Ҫ���� �� textn
...
HELP
	);
	return 1;
}


