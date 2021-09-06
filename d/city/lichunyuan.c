// Room: /d/city/lichunyuan.c
// Verified By Numa @Sj 00-05-28
// Modified By Numa@SJ 00-09-16

#include <ansi.h>
#define HERE "/d/city/lichunyuan"
#define THERE "/d/city/xidajie3.c"
#define MAO "/d/city/dongxiangfang.c"
#define this_quest_is_open "yes"

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
��������ݳ������Ĵ�Ժ��֮һ����Ժ�����Ƴ��ϣ�Ժ����һƬ˿���
��Ц֮�����м��ּ����Ų�ö��������־ƣ��������ϸ账����һƬ��ƽ��
���ϰ�����ǵ��������¹����������Τ����, ������������Ц����ͣ��
LONG
	);

	set("exits", ([
                "east" : __DIR__"dongxiangfang",
                "west" : __DIR__"xixiangfang",
		"south" : __DIR__"mingyufang",
	]));

	set("objects", ([
		__DIR__"npc/xiaosong" : 1,
		__DIR__"npc/wei" : 1,
                __DIR__"npc/yanxiao2" : 1,
                __DIR__"npc/yanxiao" : 1,
        	__DIR__"npc/guinu" : 1,
	        __DIR__"npc/yanshang" : 2,
	]));

	set("coor/x",100);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",20);
   set("coor/z",0);
   set("coor/x",100);
  set("coor/y",20);
   set("coor/z",0);
   set("incity",1);
	setup();
}

void init()
{
	object me = this_player();
	
//   if (geteuid(me) == "reikou" || me->query("env/debug")) call_out("do_happen1",10,me); �գ���һ�����ţ�hongba����
    if (this_quest_is_open == "yes"
     && userp(me)
     && !me->query("mao18/pass")
        && me->query_temp("mao18/jg_pass")
     && me->query("age") <=20
     && random(me->query_int()) > 20
     && random(me->query_kar()) > 22) {
        remove_call_out("do_happen1");
		call_out("do_happen1",10,me);
        }
}

int do_happen1(object me)
{
	if (base_name(environment(me)) != HERE)
		return 1;
	tell_object(me,HIY"
    ��Ȼ֮�䣬���Ϸ���ͬʱ������������ߺ�ȣ�������Ժ�������ϵ����ѣ������ǣ���

��������������ǣ��������ţ���������һ���ˣ������˲�����ɣ�˭�������ҽ��Ҷ���

�����Ը��ģ��ɱ�����ǲ���������һ��ߺ��֮����������������Ƭ�̣����Ÿ���Ժ

������������Ů�Ӿ����������ӽ��������ҳ�һ�š�\n"NOR);
    if (random(me->query_con()) > 14) {
		message_vision(HIR"\n$N���˼������Ѽ������ʣ���������ȥ��\n"NOR,me);
        remove_call_out("do_happen2");
        call_out("do_happen2",4,me);
		return 1;
	}
	message_vision(HIR"\n$NͻȻȫ�������ŵķ�Ҳ�Ƶ����˳�ȥ��\n"NOR,me);
	me->move(THERE);
	tell_room(environment(me),HIG + me->name(1) + "ͻȻ���п������ɱ������������������Ժ���˳�����\n"NOR);
	return 1;
}

int do_happen2(object me)
{
	if (base_name(environment(me)) != HERE)
		return 1;
	tell_object(me,HIW"
    ���һ��������ײ����ӿ��ʮ�߰�����װ�������ײ���ͷ����������Ĵ󺺡�

    ��������һ����ʮ��������߱�ȭ�������ң�����������Ĺ��˹��֣���������������

��ػ��ռֵ����ѡ������������֣��ڲ��������\n"NOR);
        if (random(me->query_kar()) > 18) {
		tell_object(me,HIR"
    ��Ȼ�����᷿���и��ֺ�������˵��������˭��������С�У���������Ѱ����\n"NOR);
        remove_call_out("do_happen3");
        call_out("do_happen3",4,me);
		return 1;
	}
    tell_object(me,HIY"\n�����ֻ�������˴�ܣ�û����˼�����Թ������ˡ�\n"NOR);
	me->move(THERE);
	tell_room(environment(me),HIG + me->name(1) + "��ͷ���ԵĴ�����Ժ���˹�����\n"NOR);
	return 1;
}

int do_happen3(object me)
{
	if (base_name(environment(me)) != HERE)
		return 1;
	tell_object(me,HIC"
    ���������ϼ�����������ȥ�������м�һ����״����ڴ��ϣ�ͷ�ϰ��˰ײ�������

���޵��̣���Ȼ���Ǽ������������ߴ����ʵ��������º����֣��������մ�������

    ����������������������ʲô��ʲô��������Ȼ��ʲô��ʲô����С�ӣ�����үү

������Ҳ�����ˡ���\n"NOR);
	if (present("wei chunfang",environment(me))) {
		tell_object(me,HIR"
    վ��һ�Ե��ڼ�Ů֮�У�ͻȻ�и���ʮ����������Ů��������һ����Ц�˳�����һ

��˽�η�������һ�����������Ƕ��⣬����Ǽ�Ů�������������������������������

����ӣ���ʲô��Ц�����Ǽ�Ů�ŵò�����˵��\n"NOR);
        remove_call_out("do_happen4");
        call_out("do_happen4",4,me);
		return 1;
	}
	tell_object(me,"����˰���Ҳ������ɶ���������Թ������ˡ�\n");
	me->move(THERE);
	tell_room(environment(me),HIG + me->name(1) + "��ͷ���ԵĴ�����Ժ���˹�����\n"NOR);
	return 1;
}

int do_happen4(object me)
{
	if (base_name(environment(me)) != HERE)
		return 1;
	tell_object(me,HIY"
    �㿴��أ���������ͳ���ǰȥ�����Ǹ���������һ�ţ��պ��������˵����ҡ�

    ��������ȭ����������ͷ�����䡣����ǰһ�壬�޵ؿɱܣ��㼴�ƿ��᷿���ţ�

���˽�ȥ��\n"NOR);
	me->move(MAO);
	if (present("mao shiba",environment(me))) {
		tell_object(me,HIR"
    ֻ�������������������ͽ���˷��ڵ����ɡ�������һ������̧��������ߣ�

�׷׶��Ŷ�ȥ��
    
    ������󺺺�������������һ�����ֳ������ӣ�������������ʹ���������һ����

���ȥ�����������˵�����ʰ�𵶣��ݸ��ң�����ʰ����µ��������������֡�\n"NOR);
        call_out("do_happen5",3,me);
		return 1;
	}
	tell_object(me,"�������Ҳûʲô�ˣ��͸Ͻ�������������ˡ�\n");
	me->move(THERE);
	tell_room(environment(me),HIG + me->name(1) + "��ͷ���ԵĴ�����Ժ���˹�����\n"NOR);
	return 1;
}

int do_happen5(object me)
{
	tell_object(me,HIY"
    �������˵����������������С���ѻ������������ã�������Ҫ��ȥ������ʤɽ

�ͱ��˱��䣬�����Ը��ǰȥ���͸���һ���ߡ�("RED"yes"HIY"|"RED"no"HIY")\n"NOR);
	me->set_temp("mao18/passed1",1);
	return 1;
}

/*
int do_yes()
{
	object me = this_player();
	object ob;
	
	if (!me->query_temp("mao18/passed1"))
		return 0;
	if (!(ob = present("mao shiba",environment(me))))
		return notify_fail("éʮ�˶������ˣ���\n");
	tell_object(me,HIW"
    ������˵��������ô��ȥ���������и�ͬ������ͬ������

    ���˹�����Ц��˵�����������仰˵�úá������ڽ���������˵���˼�ǧ�飬�и���

��ļһ���ö��ˣ�����ͬ������ȴ�����������������߰գ���\n"NOR);
	call_out("do_go",1,me);
	return 1;
}

int do_no()
{
	object me = this_player();
    object ob;
	
	if (!me->query_temp("mao18/passed1"))
		return 0;
	if (!(ob = present("mao shiba",environment(me))))
		return notify_fail("éʮ�˶������ˣ���\n");
	tell_object(me,HIW"
    ��ս���Ĵ������С�˼��С��������л���Щ�£����ү���ͷŹ�С���Ұɣ���

    ���˹�����Ц��˵������������С�һ�Ҳûʲô�������Ͽ���ɣ���\n"NOR);
	me->delete_temp("mao18/passed1");
	return 1;
}
	
*/
