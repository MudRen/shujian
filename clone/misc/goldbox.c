// box.c ������

#include <ansi.h>
#define PAY_TIME 259200

inherit ITEM;
inherit F_SAVE;

void create()
{
	set_name(HIW "����վ" NOR, ({ "huishou zhan", "zhan", "box" }) );
	set_weight(999999);
	set_max_encumbrance(9999999);
	//if( clonep() )
	//	set_default_object(__FILE__);
	//else {
		set("unit", "��");                
		set("value", 1000);
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
		set("amount",30);
	//}
	set("no_start",0);
	restore();
	set("long", "�������������BUG�Ƿ����ƽ�Ǯ������ϵͳΪ����ṩ�⳥��������õ�һ������վ��\n��ҿ���ͨ�����(jiancha)���鿴��Щ������bug�����ල�˴��ջطǷ���Ǯ�Ĺ��̡�\n���ù�BUG�������������put������Ƿ�Ľ�Ǯ��\n");
	setup();
}

int is_container() { return 1; }

void init()
{
/*
	if( me->query("combat_exp") <= 5 
	&&  this_object()->query("amount") >=10 
	&&  random(2) == 1 )
	{
		ob=new("/clone/money/silver");
		ob->set_amount(10);
		ob->move(this_object());
		tell_object(me, HIW "\n���Ȼ��������������ʲô�������������⣡\n\n" NOR);
		me->add("combat_exp", 1);
	}
*/

	add_action("do_put", "put");
	add_action("do_check",({"check","jiancha"}));
}

int to_num(string str)
{
	string* get;
	int temp;
	int ret=0;
	
	if(!str || strlen(str)<2 ) return 0;
	if(str[0..1]=="ʮ") str = replace_string(str,"ʮ","10|");
	else str = replace_string(str,"ʮ","0|");
		
	str = replace_string(str,"��","");
	str = replace_string(str,"��","0000|");
	str = replace_string(str,"ǧ","000|");
	str = replace_string(str,"��","00|");
	//	
	str = replace_string(str,"��","9");
	str = replace_string(str,"��","8");
	str = replace_string(str,"��","7");
	str = replace_string(str,"��","6");
	str = replace_string(str,"��","5");
	str = replace_string(str,"��","4");
	str = replace_string(str,"��","3");
	str = replace_string(str,"��","2");
	str = replace_string(str,"һ","1");
	
	get = explode(str,"|");
	for(int i=0;i<sizeof(get);i++)
	{
		if(!get[i] || get[i]=="") continue;
		if(sscanf(get[i],"%d",temp)!=1) continue;
		ret += temp;
	}
	return ret;
}

string query_save_file()
{
	return "/data/money";
}

string get_msg(int t)
{
	if(!t) return "��";
	return sprintf("%s��"HIY"�ƽ�"NOR,chinese_number(t) );
}

int do_check(string arg)
{
	//if(!arg) �������ڲ������
	int line,coin;
	string msg,name,id;
	string* ids;
	mapping gold=([]);
	object me = this_player();
	if(arg=="start" && wizardp(me) )
	{
		if(query("no_start")==1) return notify_fail("�Ѿ���ȡ�������ˡ�\n");
		line=0;
		while( msg = read_file("/log/static/HOWG",line,1) )
		{
			if(!msg) continue;
			line++;
			coin=0;
			msg = strip(msg);
			if(sscanf(msg,"%*s2004 %s(%s)����%s",name,id,msg)!=4) continue;
			
			if(SECURITY_D->get_status(id) !="(player)") continue;
			
			if(undefinedp(gold[id])) gold[id]=0;
			
			/// all change to gold
			if(strsrch(msg,"��ҼǪ����Ʊ")!=-1)
			{
				msg = replace_string(msg,"��ҼǪ����Ʊ","");
				gold[id] += to_num(msg)*10;
				continue;
			}
			
			if(strsrch(msg,"���ƽ�")!=-1)
			{
				msg = replace_string(msg,"���ƽ�","");
				gold[id] += to_num(msg);
				continue;
			}
			/*			
			if(strsrch(msg,"������")!=-1)
			{
				msg = replace_string(msg,"������","");
				gold[id] += to_num(msg)*100;
				continue;
			}
			
			if(strsrch(msg,"��ͭǮ")!=-1)
			{
				msg = replace_string(msg,"��ͭǮ","");
				gold[id] += to_num(msg);
				continue;
			}
			*/
		}
		set("no_start",1);
		set("start_time",time() );
		set("gold",copy(gold));
		save();
		write("�Ѿ���ȡ������ϣ�\n");
		return 1;
	}
	gold = query("gold");
	if(!gold || !mapp(gold))
		return notify_fail("��ʧ���ʽ��Ѿ�ȫ��ȡ�أ���л֧�֣�\n");
	ids = keys(gold);
	if(!ids || !sizeof(ids)) return notify_fail("��ʧ���ʽ��Ѿ�ȫ��ȡ�أ���л֧�֣�\n");
	msg = "Ŀǰ��Ƿծ����Լ���Ƿծ��Ǯ��\n";
	for(int i=0;i<sizeof(ids);i++)	
	{
		if(gold[ids[i]]==0)
		{
			map_delete(gold,ids[i]);
			continue;
		}
		if(me && getuid(me)==ids[i]) msg += HIR"";		
		msg += sprintf("���:%-8s����Ƿ%s\n",ids[i],get_msg(gold[ids[i]])   );
		//MONEY_D->money_str(gold[ids[i]])
		msg += NOR"";
	}
	msg += "�뼰ʱ��������ծ�����ڽ��������߼�¼����ID��������������\n";
	
	if(PAY_TIME-(time()-query("start_time")) >0)
		msg += "��������޻���"+CHINESE_D->chinese_time(PAY_TIME-(time()-query("start_time")))+"��\n";
	else msg += "����Ա����ѯ���߼�¼׼�������ù�BUG����ID���������ͷ���\n";
	
	me->start_more(msg);
	return 1;
}

int do_put(string arg)
{
	object me, obj;
	string item, target; 
	string id;
	int amount;
	mapping gold = query("gold");
	
	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target)!=2 
	||  sscanf(item, "%d %s", amount, item)!=2
	||  !objectp(obj = present(item, me)) )
	{
		write("��ʽ��put [����] [Ǯ] in huishou zhan��\n");
		return 1;
	}
	
	if(member_array(target,parse_command_id_list())==-1)
	{
		write("��Ҫ��Ǯ�ŵ����\n");
		return 1;
	}
			
	if(amount<1 ||amount>99999999)
	{
		write("?����������bug\n");
		return 1;
	}
	
	if(!obj->query("money_id"))
	{
		write("�ⲻ��Ǯ��\n");
		return 1;
	}
	if(obj->query_amount() < amount)
	{
		write("������û����ô��"+obj->name()+"��\n");
		return 1;
	}
	
	if(obj->query("money_id")!="gold" && obj->query("money_id")!="thousand-cash" )
	{
		write("�⳥�ĵ�λ������ �ƽ� ���� ��Ʊ��\n");
		return 1;
	}
		
	id = getuid(me);
	
	if(!gold){
		write("�������ϣ�������\n");
		return 1;
	}
		
	if(undefinedp(gold[id]))
	{
		write("�㲢û��ǷǮ��\n");
		return 1;
	}
	tell_room(environment(me),me->name()+"�ó�һЩǮ����"+this_object()->name()+"�\n",({me}));
	tell_object(me,"���ó�"+chinese_number(amount)+obj->query("base_unit")+obj->name()+"����"+this_object()->name()+"�\n");
	log_file("static/HOWG_BACK",sprintf("%-8s(-8%s) ����ϵͳ %d value",me->name(1), geteuid(me),amount*(int)obj->query("base_value") ),this_object() );
		
	gold[id] -= amount*(int)obj->query("base_value")/10000;//c
	obj->add_amount(-amount);
	
	if(gold[id]==0)
	{
		write("������Ѿ����ˣ���л֧�֡�\n");
		map_delete(gold,id);
		save();
		return 1;
	}
	if(gold[id]<0)
	{
		write("̫���ˣ����㡣\n");
		MONEY_D->pay_player(me,-gold[id]*10000 );//c
		message_vision("��$N��ͻȻ�ĳ�ЩǮ������$n���\n",this_object(),me);
		map_delete(gold,id);
		save();
		return 1;
	}
	if(gold[id]>0)
	{
		write("nod,�㻹Ƿ"+get_msg(gold[id])+"���뾡�컹�塣\n");
		save();
		return 1;		
	}
	write("���к��£���ciweiȥ��\n");
	return 1;
}



























/*
int do_put(string arg)
{
	object me, obj;
	string item, target; 
	int amount;

	me = this_player();

	if( !arg || sscanf(arg, "%s in %s", item, target)!=2 
	||  sscanf(item, "%d %s", amount, item)!=2
	||  !objectp(obj = present(item, me)) )
		return 0;

	if( obj->query("money_id") == "silver" 
	&&  obj->query_amount() >= 5 && amount >= 5 ) 
	{
		if( me->query("begger") > 0) {
			message_vision( sprintf(HIY "$N��һ%s%s�Ž�%s��\n" NOR,
				obj->query("unit"), obj->name(), 
				this_object()->name()),me );
			obj->set_amount(obj->query_amount() - amount);;
			me->add("begger", (-1)*(amount/5));
			if( me->query("begger") < 0) me->set("begger", 0);
			this_object()->add("amount", amount);
			return 1;
		}
	}
	return 0;
}
*/