#include <ansi.h>
#include <room.h>
#include <wanted.h>
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
���Ų����У��ٲ�̤���ľ��ǰ������ݣ�����û��·,ÿ��һ����������
���̵�С��,����������塣
LONG
        );
	set("outdoors", "����");

	set("exits", ([
		"south" : __DIR__"shanlu11",
		"north" : __DIR__"shanlu11",
		"west" : __DIR__"shanlu11",
		"east" : __DIR__"shanlu11",
	]));

	setup();
}

void init()
{
	object me = this_player();

	if( me->query(QUESTDIR1+"pass_shanlu") 
	 && me->query_skill("lingbo-weibu", 1) < 140
	 && ! is_wanted(me)){
		me->move("/d/dali/wuliang/gaoshan", 1);
		message_vision(HIR"$N��Ϥ���ƹ�ɭ�֣�����һ����ɽ�ϡ�\n"NOR, me);
	}
	if (random(me->query("kar")) <10 && me->query_con() < 30){
		me->set_temp("last_damage_from", "��ɭ�����ƣ������");
		me->add("qi", -30);
		me->add("jingli", -10);
		me->receive_wound("jing", 20);
	}
	else {
		me->add("qi", -20);
	}
	add_action("do_look", "look");
}

int do_look()
{
	object me = this_player();
	mixed *local;
	local = localtime(TIME_TICK);
	if(local[2] < 6 &&random(6)<2) {
	message("vision",BLU"�����,���������һƬ�����ֲ�����ָ,���Ĵ�������,��������־�.\n"
				"ͻȻ��������Ұ�޵ĺ���,���ŵĿ�������.\n"NOR, me);
	}
}
int valid_leave(object me, string dir)
{
	mixed *local;
	int i = 0;

	local = localtime(TIME_TICK);

	if (dir == "west")
		me->add_temp("mark/steps",1);
	if (dir == "south")
		me->add_temp("mark/step",-1);
	if (dir == "east")
		me->add_temp("mark/steps",-1); 
	if (dir == "north")
		me->add_temp("mark/step",1);

/**for Ӫ�ȶ��� ***/
// Modify By River ���ڲ���̫�򵥻�� lbwb ��ֻ�����λ��� 

// Modify By tangfeng Quest����˭���Խ�ģ��������õ������Ƿ������貨΢��

	if (me->query_temp("mark/steps") == me->query_temp(QUESTDIR1+"steps") 
	 && me->query_temp("mark/step") == me->query_temp(QUESTDIR1+"step"))
		i = 1;
	if( wizardp(me))  tell_object(me,HIR"\ni="+i+".\n"NOR);
	if (i
		&& local[2] < 6
		&& me->query_temp(QUESTDIR1+"yingjiu")
		&& !me->query_condition("killer"))
	{
		me->move("/d/dali/wuliang/gaoshan");
		me->set(QUESTDIR1+"pass_shanlu", 1);
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail(HIR"\n���ߵ���һ����ɽ�ϡ�\n"NOR);
	}
	if((me->query_temp("mark/steps") < -10 
	 || me->query_temp("mark/step") < -10 
 	 || me->query_temp("mark/steps") > 12 
	 || me->query_temp("mark/step") > 12 ) && !random(20))
	{
		if(me->query_temp(QUESTDIR1+"yingjiu"))  me->set("quest/�����˲�/time", time());
		me->move("/d/dali/wuliang/xiaoxi");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		if( me->query_temp(QUESTDIR1+"yingjiu")){
			me->delete_temp("quest/�����˲�");
			me->delete_temp("quest/busy");//�����ͻ��־ȡ��
			return notify_fail(HIW"\n���ƣ�������߳����ɽ·����ɥ�ط����Լ���ôҲ�Ҳ����Ĵ���˵����١�\n"NOR);
		}
		else return notify_fail(HIY"���ƣ�����������߳������ɽ·��\n"NOR);
	}
	return ::valid_leave(me, dir);
}
/*
int valid_leave(object me, string dir)
{
	mixed *local;
	int i = 0;

	local = localtime(TIME_TICK);

	if (dir == "west")
		me->add_temp("mark/steps",1);
	if (dir == "south")
		me->add_temp("mark/step",-1);
	if (dir == "east")
		me->add_temp("mark/steps",-1); 
	if (dir == "north")
		me->add_temp("mark/step",1);

	if (me->query_temp("mark/steps") == me->query_temp("duanyu/steps") 
	 && me->query_temp("mark/step") == me->query_temp("duanyu/step"))
		i = 1;
	if (i
	 && (random(me->query("kar"))+random(me->query("int"))) > 50
	 && (random(me->query_con(1))+random(me->query_int(1))) > 75
	 && local[2] < 6 
	 && local[2] >= 3
	 && me->query_temp("duanyu/find2")){
		me->move(__DIR__"gaoshan");
		log_file("quest/lbwb",
			sprintf("%-18s˳��ͨ��ɽ·������Ѱ���貨΢��֮·������%d����%d������%d����%d��\n",
				me->name(1)+"("+capitalize(getuid(me))+")", 
				me->query("kar"),
				me->query("int"),
				me->query_con(1),
				me->query_int(1)
			), me
		);
		me->set("quest/dali/shanlu", 1);
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail("���ߵ���һ����ɽ�ϡ�\n");
	}
	if (me->query_temp("mark/steps") < -8 
	 || me->query_temp("mark/step") < -8 
 	 || me->query_temp("mark/steps") > 10 
	 || me->query_temp("mark/step") > 10 
	 || i && !random(30)) {
		if(me->query_temp("duanyu/find2")){
			me->add("quest/dali/fail", 1);
			me->set("quest/dali/time", time());
			log_file("quest/lbwb",
				sprintf("%-18s��%d�λ���û�����գ�δ��˳��ͨ��ɽ·��\n",
					me->name(1)+"("+capitalize(getuid(me))+")", 
					me->query("quest/dali/fail")
				), 
			me);
		}
		me->move(__DIR__"xiaoxi");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		if( me->query_temp("duanyu/find2")){
			me->delete_temp("duanyu");
			return notify_fail(HIW"\n���ƣ�������߳����ɽ·����ɥ�ط����Լ���ôҲ�Ҳ����Ĵ���˵����١�\n"NOR);
		}
		else {
			me->delete_temp("duanyu");
			return notify_fail("���ƣ�����������߳������ɽ·��\n");
		}
	}
	return ::valid_leave(me, dir);
}
*/
