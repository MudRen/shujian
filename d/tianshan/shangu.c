// Room: /d/tianshan/shangu.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������ɽɽ�����һ��ɽ�ȡ�������ȥ������һЩаħ����ڴ˾ۻᣬ��
Щ��������Ů���п��г󣬼���ɮ�ˣ����е�ʿ���еĴ���ƮƮ���е�խ�¶�
���е��ǳ����������̣��е������ٸ��ʵ�Ů�ӣ����ζ������ι�״����
������ʿ����ͬ��һ����˳��б��У�����Ҳ������Ź֣�˵������Ŀ��
LONG);    
        set("objects", ([
                __DIR__"npc/wulaoda" : 1,
		__DIR__"npc/zhangdafu" : 1,
        ]));   
	set("outdoors", "��ɽ");
	setup();
}

void init()
{
	object me = this_player();
	if ( me->query_temp("tonglao/pass2")) {
		me->add_busy(4 + random(4));
		remove_call_out("tonglao_help");
		call_out("tonglao_help", 4, me);
	}
}

void tonglao_help(object me)
{
        object ob;
        if (!me) return;
        tell_object(me, HIW"\n��ͻȻ��ֻ�������˴����������ڼ��ֵܣ�����ȡ�����У�ÿ������Ů����\n"
		"����һ��������һ������Ů���������С�����Ǹ��ưͣ��վ�����翷�����\n"
		"�����ĵ�ͷ�ȹ��������ϵ�Ѫ���Ӵ˸���翷��Ʋ�������������Ҫ��������\n"
		"�⣬��Ҳ��������η�������ˡ�����һ˵�꣬�������ͷ�����֣��ӵ�������\n"
		"���ڲ����е�Ůͯ������ȥ��\n"NOR);
	tell_object(me, HIY"\n������˾����ͷ����Ҫ����һ��ȫ�޿���֮�����ư�Ů�������ɵôȱ��Ĵ�\n"
		"�������벻��˭��˭�ǣ���Ů���ǷǾȲ��ɵģ���������ʯ����彫��������\n"
		"�˲������ߡ�\n"
		"һ�����������ĵ���Ȼ������\n"NOR);
	tell_object(me, YEL"\n��Ų���·������������ï�ܣ������˽�ȥ�����˽�������ʱ������˿�����ۡ�\n"
		"�ֱ���һ�󣬽ŵ���̤�������Ļ�ѩ��ԭ���ѱ���ɽ����\n"NOR);
	ob = new(__DIR__"obj/bag");
	ob->set_temp("owner",me->query("id"));
	ob->move(me);
	me->delete_temp("tonglao");
	me->set_temp("tonglao/pass3",1);
	me->set_temp("tonglao/call",1);
	me->add("shen",5000+random(5000));
	me->move(__DIR__"shanyao");
	return;
}
