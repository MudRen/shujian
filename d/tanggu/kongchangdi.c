#include <ansi.h>
inherit ROOM;
string look_leitai();
string look_qi();
string look_board();

void create()
{
        set("short", HIY"�㳡�յ�"NOR);
        set("long", "�˴�������������֮����ֻ����¥�����廧���ţ��񳵾�פ���������ۡ�һ
Ƭ�����ĳ����ϣ�������ǰ�������������Ȳ�֮�������ڶ���ԶԶ��ȥ��Χ�źô�
һ���ˣ�ֻ���м��ϴ�һ��յأ�����һ��"NOR+HIR"��̨"NOR+"�����²���һ����죨Qi�����׵�
�컨�����š�"NOR+HIY"���� ����"NOR+"���ĸ����֣�����һ��װ壨Board����������������ȭ��
��ȥ�Ĵ�����֣�һ���Ǻ�����Ů��һ���ǳ����ӡ�\n");

        set("no_fight", 1);
        set("no_sleep_room", 1);
        set("leitai", __DIR__"biwuleitai");
        set("exits", ([ 
			             "northwest" : "/d/tanggu/center",
        ])); 
        set("objects", ([    
             	__DIR__"npc/mu-nianci" : 1,
				__DIR__"npc/manghan" : 1,
        ]));
        set("item_desc",([            
            "qi" : (: look_qi :),
				"leitai" : (: look_leitai :),
				"board" : (: look_board :),
        ]));
        set("outdoors", "����");  
        setup(); 
}

void init()
{
	object *ob;
	object me=this_player();
	int i,p=0;
    if(me->query_condition("killer"))
	{
		message_vision(HIC"\nͻȻ�����������$N���Դ������ǺͲ���ٸ����ԡ�\n"NOR,me); 
		tell_object(me,HIR"���ţ���֪����������һֻ��ŷ���һ�ţ�����һ���߷ɳ�ȥ��\n"NOR);
		me->move("/d/xiangyang/damen");
		tell_room(environment(me), HIR"\nֻ��"+ me->name()+ "���һ���ɹ�����ˤ�˸�����ʺ����˧Ŷ~~~~~~~~\n"NOR, ({ me }));
		me->start_busy(1);
		return;
	}
    
	ob = all_inventory(this_object());
	i = sizeof(ob);
	while (i--) {
		if(userp(ob[i])) p++;
	}
	if( p > 15 && !wizardp(me))
	{
		me->start_busy(1);
		me->move("/d/xiangyang/damen");
		tell_object(me,query("short")+"�Ѿ�����Ϊ�����㼷����ȥ��\n");
		return;
	}
	add_action("do_chihe",({"chihe"}) );
	add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
                             "kill", "fight", "study", "practice","exercise", "exert",}));
}
int do_chihe(string arg)
{
     object obj,me = this_player();
	 int money = 50000;		 
	 if(arg) return 0;
	 obj=present("mu nianci",this_object());
	 if(!obj) return 0;
	 if(!me->query_temp("quest/bwzh/hoster") 
		 && !me->query_temp("quest/bwzh/biwu_host")
		 && !me->query_temp("quest/bwzh/biwu_challenge"))
	   return notify_fail(HIR"����ȶ���ЦЦ������λ"+RANK_D->query_respect(me) +"���ﲻ�ṩ��ʳ��\n"NOR);
	 
	 if (me->query("food") > (me->query("str")*3+50) && me->query("water") >(me->query("str")*3+50))
	   return notify_fail(HIR"����ȶ���ЦЦ������λ"+RANK_D->query_respect(me) +"���Ӳ���ר�ı���ɣ�\n"NOR);

	 if(me->query("balance")<money)
	   return notify_fail(HIR"����ȶ���ЦЦ������λ"+RANK_D->query_respect(me) +"���д��....Ҳ߯�ٵ�ɣ����ˣ�����ר�ı���ɣ�\n"NOR);

	 message_vision(HIC"\n$N��������Щ���Ӽ���ֻ����ߵ�����Ȱ���һ�У��߹�һ��С���������С���Ը��˼��䡣\n"NOR, me);
	 message_vision(HIG"һ��������˸�$N����һЩ���ˡ��������Ŀ����$Nˬ��ش��һ�١�\n"NOR, me);
	 message_vision(HIY"����ȴ���$N��������ص�����������"+MONEY_D->money_str(money)+HIY"�����Ѿ�ί�������Զ�ת���ˡ�\n"NOR, me);
	 
	 me->add("balance",-50000);
	 me->add("food", me->query("str")*10+100);
     me->add("water", me->query("str")*10+100);
	 return 1;
 }

string look_leitai()
{
    	object me, room;
    	me = this_player();
    
    	if (me->is_busy()) 
          	return "����æ���ء�\n";
    	me->start_busy(2);
    	if (!(room = find_object(query("leitai"))))
          	room = load_object(query("leitai"));
        if( !room ) 
        	return "������̨û��׼���ã���֪ͨ��ʦ��\n";  
    	message_vision("$N������̨�ߣ��쳤�˲���������ȥ��\n", me);
    	"/cmds/std/look.c"->look_room(this_player(), room); 
    	return "";
}
string look_qi()
{
    	object me,obj,who;
		string str;
		int i,p;
    	me = this_player();
    	if (me->is_busy()) 
          	return "����æ���ء�\n";
    	me->start_busy(2);
		str  = "һ����죬�׵׺컨�����š�"+HIY"��������"NOR+"�������¼���С�֣�\n\n";
		str += "        ��"+HIC"�Ի������أ�����������"NOR+"��\n\n";
		obj=present("mu nianci",this_object());
		if(obj && obj->query("station") && obj->query("bwzh/host_player"))
		{
			who=obj->query("bwzh/host_player/object");
			if(!who) return "";
			i=who->query("age")-obj->query("bwzh/age");
			if(i<18) i=18;
			p=who->query("age")+obj->query("bwzh/age");
			if(p>80) p=80;
			str += HIC"�ڽ���Ĳ���һ�ǣ�д��һ�����֣�"+obj->query("bwzh/host_player/name")+"��\n"NOR;
			str += HIC"��������ע���������֣�"+obj->query("bwzh/exp")+"|"+obj->query("bwzh/per")+"|"+i+"|"+p+"��\n"NOR;
		}
        tell_object(me,str);
    	return "";
}
string look_board()
{
    	object me,obj;
		string str;
    	me = this_player();
    	if (me->is_busy()) 
          	return "����æ���ء�\n";

    	me->start_busy(2);
		obj=present("mu nianci",this_object());
		if(!obj || !obj->query("bwzh/winner_player"))
		{
			str  = "һ��װ壬���Ϸ�д�š�"+HIY"��������"NOR+"�����⣬����ȴʲôҲûд��\n";
		}
		else
		{
			if(obj->query("bwzh/challenge_player"))
				str  = "һ��װ壬���Ϸ�д�š�"+HIY"��������"NOR+"�����⣬����Ҳд�������֣�\n";
			else 
				str  = "һ��װ壬���Ϸ�д�š�"+HIY"��������"NOR+"�����⣬����Ҳд��һ���֣�\n";

			str += "\n             ��"+HIC"��  ��"NOR+"����"+obj->query("bwzh/winner_player/name")+"\n";
			if(obj->query("bwzh/challenge_player"))
				str += "             ��"+HIC"��ս��"NOR+"����"+obj->query("bwzh/challenge_player/name")+"\n";
		}
        tell_object(me,str);
    	return "";
}
int do_action(string arg)
{
	this_player()->start_busy(2);
   	write("\n����Ҫ����������ͻȻ�������˽���һ�ģ��úÿ����䣬���Ҷ���\n\n");
   	return 1;
}
int valid_leave(object me, string dir)
{

   if (me->query_temp("quest/bwzh/hoster") ||me->query_temp("quest/bwzh/biwu_host")||me->query_temp("quest/bwzh/biwu_challenge"))
	   return notify_fail(HIR"����ȶ���ЦЦ������λ"+RANK_D->query_respect(me) +"����ר�ĵ�������װɣ�\n"NOR);
   me->delete_temp("quest/bwzh");
   return ::valid_leave(me, dir);
}





