// Room: /d/dzd/matou.c
#include <ansi.h>
inherit __DIR__"dzd_room";

int do_leave(string arg);

void create()
{
	set("short","��ͷ");
	set("long",@LONG
�����Ǵ��ǵ�����ͷ��ȴû���κδ�ֻͣ�����Ե��������塣��ĿԶ����
ֻ������һɫ,������ӿ.�Ա�أ��һ����ʯ(rock)��������ӿ����ʯȴ��Ȼ������
������ֻС����������Բ鿴(chakan)�������Ҳ������ʱ�뿪(leave)��
LONG
	);
	set("item_desc",([
	"rock" : HIC"�������������죬�Ь���򺣶��ߡ�\n"
	         HIC"������ȥ�޶�·��ֻ��̶������ǰ��\n"NOR,
	]));
	set("no_fight",1);
	set("outdoors","���ǵ�");
	set("exits",([
		"northeast" : __DIR__"haitan3",
		"northwest" : __DIR__"haitan1",
		"north" : __DIR__"haitan2",
		]));
	set("objects",([
		__DIR__"npc/npc_dzd" : 1,
		MISC_D("dzd_flag"):1,
		]));
	setup();
}
void init()
{
	object me = this_player();
	::init();
	add_action("do_leave",({"leave","likai"}) );
	if (me && environment(me) == this_object() && userp(me) )
		call_out("do_push",30+random(30),me);
}
void do_push(object me)
{
	if(!me) return;
	if (environment(me) == this_object() ) {
		message_vision("һ���˲��ͷ��غ�ߴ������˭����ô����������Ҫô��ﹰ$N���ˡ�\n",me);
		"/cmds/std/go"->main(me,"north");
		//me->move("/d/dzd/haitan2");
	}
	return;
}
int valid_leave(object me,string dir)
{
	if(me->query_temp("job_xkd/dead"))
		return notify_fail("����ȥ����\n");
	return 1;
}

int do_leave(string arg)
{
	if(!this_player()) return 0;
	if(!this_player()->query_temp("job_xkd/dead")) return notify_fail("��û��ȥ�ʹ����ù��˰���\n");
	write("��Ȼ��ˡ�������������\n");
	this_object()->backhome(this_player());
	return 1;
}
/*
���Ⱔ�� ^_^		
int valid_leave(object me,string dir)
{
	int i,j;
	string *oblist1,*oblist2;
	object *obj;
	oblist1 = ({"jiedu wan","huoxue dan","chantui yao","chuanbei wan","danggui dan","fuling wan","yannian dan","liaojing dan",
			"jinchuang yao","xujing dan","jinchuang yao","xujing dan","buqi wan","yangjing dan","yuling san","yuzhen san",
			"heishi dan","baicao dan","wulong gao","qingxin san","huxin dan","baola wan","renshen guo","xue lian"});
	oblist2 = ({"wujin beixin","bishou","ziwei jian","wangnangu dujing"});

	obj = all_inventory(me);
	j = sizeof(obj);
	for(i=0;i<j;i++) {
		if(member_array(obj[i]->query("id"),oblist1) != -1 && (dir == "north" || dir == "northeast" || dir == "northwest")) {
			
			message_vision("�и��˴��Ա߹�������$N���ϵ�" + obj[i]->name() + "�����ˣ�\n",me);
			destruct(obj[i]);
			return notify_fail("�㲻�ܴ�����ʥҩ����ð�գ�\n");
		}
		if(obj[i]->query("unique") && member_array(obj[i]->query("id"),oblist2) == -1 && (dir == "north" || 
				dir == "northeast" || dir == "northwest")) {
			
			message_vision("�и��˴��Ա߹�������$N���ϵ�" + obj[i]->name() + "�����ˣ�\n",me);
			destruct(obj[i]);
			return notify_fail("�㲻�ܴ��������ð�գ�\n");
		}
	}
	return ::valid_leave(me, dir);
}
*/