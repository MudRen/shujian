// shulin1.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;


void create()
{
	set("short", "ɽ������");
	set("long", @LONG
�������£������ȣ����о����ĵģ���˵�˼�����������Ҳ�ް�㣬Ψ
��������䣬ң��ͺ��������ٲ��������Ͽ�ȥ��ֻ���ٲ�֮��һ��ʯ�ڹ���
���񣬲�֪������ĳ弤ĥϴ���Ž������ʯ��ĥ�����ƽ����������ˮ����
�٣��Ž���Ƭ����������������ʯ��¶�˳�����
LONG
	);
        set("exits", ([
              "south" : __DIR__"donghubian",
	]));
        set("outdoors", "����"); 
	set("objects", ([
	   __DIR__"obj/yeguo" : 2,
	]));
 
	setup();
}

void init()
{
        add_action("do_move", "enter");
        add_action("do_jump", "climb");
        add_action("do_look", "look");
}

int do_move(string arg)
{
	object me;
 	me = this_player();
	message_vision("$N�ǿ�Ұ�����ԣ������Ժ��߹�ȥ��\n" NOR, me);
	me->move(__DIR__"shuhou");
	return 1;
}

int do_look()
{
	object me = this_player();
	mixed *local;
	local = localtime(time() * 60);


	
	if((local[2] < 2 || local[2] >= 23) && me->query("marks/xiaoyao")== "wait2" )
	{
		write(HIC"    ��һƳ�ۼ䣬��������ʯ���������вʹ�����������ȥ����Ȼ��һ�ѳ�����Ӱ\n"
		         "�ӡ�����Ӱ�и������ʺ�һ����ι⣬��˸���������߲�����\n"NOR, me);
                                           me->set("marks/xiaoyao","wait3");   

	}
	
		if(local[2] >= 2 && local[2] < 4 &&  me->query("marks/xiaoyao")== "wait3" )
	{
		write(HIY"    ��̧ͷһ����ԭ������������Ѿ��䵽�������ͱ�֮���ͱ�����һ���ף��¹�\n"
		         "�Ӷ��ױ˶���������������������вʹ������������������ڶ�����ظߴ���ʮ�ɣ�\n"
		         "���ɵ����´��棬��Ҫ��ȥ�������ס�\n"NOR, me);
 me->delete("marks/xiaoyao");
 me->set("marks/xiaoyao","get_book");

	}

//����������ʼ������ſ�ɱ�������˵ı�ǣ���look���������
                if(local[2] >= 4 && local[2] < 18 &&  me->query("marks/xiaoyao")== "gotofind")
	{
                write(HIW"�������£����Ʒ�ȣ������ϱ����������ͱڣ����޳�·����������һ�ԴԵĲ軨��ҡҷ���ˡ���\n"NOR, me);
                me->set("marks/xiaoyao","wait");
	}
	
		if(local[2] >= 18 && local[2] < 21 &&  me->query("marks/xiaoyao")== "wait" )
	{
		write(HIC"    ��վ��������̧ͷֻ��������Բ������ں����ϱ���ͬ����һ�����һ�㣬��\n"
                         "��˳�ź���һ·��չ��ȥ��ͻȻȫ��һ��ֻ����������Ϻ�Ȼ�и���Ӱ��\n"NOR, me);
                                me->set("marks/xiaoyao","wait1");         
	}

		if(local[2] >= 21 && local[2] < 23 &&  me->query("marks/xiaoyao")== "wait1" )
	{
		write(HIM"    ��ع�������ֻ�����Сʯ����Ҳ�и���Ӱ��ֻ�����μ�С��Ӱ��ҲŨ�Ķࡣ��ʱ��\n"
		         "Ȼ���򣺡�ԭ�������Ƚ��ҵ�Ӱ��ӳ�����Сʯ���ϣ���ӳ������Ĵ�ʯ���ϣ�����ȷ��\n"
		         "�����������轣����Ӱӳ����� ���������������������������֮�ʣ��漴�����㵸��\n"
		         "ȭ�����,���������������Ҳ���¶���������赡���Ӱ�����϶�����������ʾ�����书��\n"
		         "Խ��Խ����Ȥ���̲�ס������Ц��\n"NOR, me);
                                           me->set("marks/xiaoyao","wait2");   
	}


}



int do_jump(string arg)
{
	object me = this_player();

	mixed *local = localtime(time() * 60);
	
	if (me->is_busy() || me->is_fighting())
	{
		return notify_fail("����æ���ģ�\n");
	}
	
	if(arg != "cliff")
	{
		return notify_fail("��Ҫ����������\n");
	}
	

	if( me->query("quest/xiaoyao/pass"))
	{
		return notify_fail("���Ѿ�ȡ�����±ڿն������书�ؼ��ˡ�\n");
	}
	


	
	if ( (time() - me->query("quest/xiaoyao/time")) < 86400)
	{
		return notify_fail("�����ɽ�������ʮ�ɣ���ԥ�˰��죬���뻹�ǻ�ȥ�����Ṧ�������ɡ�\n");
	}
	

	{
		object *ob = deep_inventory(me);
		int i = sizeof(ob);

		while (i--)
		{
			if (userp(ob[i]))
			{
				ob[i]->move(this_object());
			}
		}

		message_vision(HIR"$N����������������������ȥ��\n"NOR, me);
		me->move(__DIR__"bankong1");

		if(local[2] > 4 && local[2] < 18 )
   {
                if(( random(me->query("kar")) > 26
				    && me->query("kar")  <31
			    	&& (int)me->query_dex(1) > 40
				    && (int)me->query_skill("dodge") > 300
				    && me->query("marks/xiaoyao") =="get_book"
                                    && random(15)==5
                                    && (me->query("y-card-vip")|| me->query("m-card-vip"))
                                 ))
			{
				call_out("do_wait", 6, me);
			}
			else 
			{
				call_out("do_wait1", 6, me);
			}
    	return 1;
		}

		call_out("do_wait2", 6, me);
		return 1;
	}
}

void do_wait(object me)
{
	object obj;

  obj=unew("/d/dali/obj/dodge_book1");



	tell_object(me, HIR"��С��������������ͱڼ�Ѱ������ŵص�....\n"NOR);
	tell_object(me, HIR"���������˿׶���,����ȡ����һ������\n"NOR);
	tell_object(me, HIR"�㻹��ȥ���ǰѱ�����ȴ����������֧�ˣ�ֻ�÷��عȵס�\n"NOR);


 //���������õ��貨΢����bmsg���ں��ؼ�
  obj->set("owner", me->query("id"));
  obj->move(me);       


  me->move(__DIR__"gudi");       
  me->delete("marks/xiaoyao");
  me->set("quest/xiaoyao/pass",1);

	log_file("quest/xiaoyao",sprintf("%-18sʧ��%s�κ�ɹ�����������ؼ�������%d��\n",
		me->name(1)+"("+capitalize(getuid(me))+")",
		chinese_number(me->query("quest/xiaoyao/fail")), me->query("kar")), me);

}

void do_wait1(object me)
{
	object *ob, *inv;
	int i, j;
	ob = all_inventory(environment(me));
	tell_object(me, HIR"��С��������������ͱڼ�Ѱ������ŵص�....\n"NOR);
        me->move(__DIR__"gudi");
  me->delete("marks/xiaoyao");      
	me->set("water", 666); 
	me->add("quest/xiaoyao/fail",1);
	me->set("quest/xiaoyao/time", time());
	log_file("quest/xiaoyao",sprintf("%-18s�Ӱ�յ��䣬��ȡ�������ؼ�ʧ��%s�Ρ�\n",
		me->name(1)+"("+capitalize(getuid(me))+")",chinese_number(me->query("quest/xiaoyao/fail"))), me);
	tell_object(me, HIC"�㲻С��һ��̤�գ�����������������˴�ˮ̶û��ˤ��..\n"NOR);
	tell_object(me, HIC"����������˴�ˮ̶û��ˤ��..���������������ߣ��������ᣬ���˹�ȥ��\n"NOR);
        for(i=0; i<sizeof(ob); i++) {
		inv = all_inventory(ob[i]);
		for (j = 0; j < sizeof(inv); j++)
		if (!inv[j]->query_autoload()) destruct(inv[j]);
		ob[i]->unconcious();
	}
}


void do_wait2(object me)
{
        object tmp;
        object *ob;
        int i;
	tell_object(me, HIR"��С��������������ͱڼ�Ѱ������ŵص�....\n"NOR);
	tell_object(me, HIW"�㲻С��һ��̤�գ�����������ֻ����������������Զȥ........\n"NOR);
        me->move(__DIR__"gudi");
        me->delete("marks/xiaoyao");
        me->set_temp("last_damage_from","ˤ��ɽ�µ�");
        me->add("quest/xiaoyao/fail", 1);
        me->set("quest/xiaoyao/time", time());
	log_file("quest/xiaoyao",sprintf("%-18s�Ӱ�յ��䣬������ȡ�������ؼ�ʧ��%s�Ρ�\n",
		me->name(1)+"("+capitalize(getuid(me))+")",chinese_number(me->query("quest/xiaoyao/fail"))), me);
        me->unconcious();
        me->die();
        if (tmp = present("corpse", this_object())) {
		ob = deep_inventory(tmp);
		i = sizeof(ob);
		while (i--) if (userp(ob[i])){
			ob[i]->move(this_object());
			ob[i]->set_temp("last_damage_from","ˤ��ɽ�µ�");
			ob[i]->die();
		}
		destruct(tmp);
		if (me) tell_room(this_object(), me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
	}
}
