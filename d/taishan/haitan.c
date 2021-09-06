//Yanqi 08/11/2k

#include <ansi.h>
inherit ROOM;

string* escapename = ({
"/d/city/xidajie1",	"/d/suzhou/yzyunhe",	"/d/city/zahuopu",
"/d/city/xjs",		"/d/city/dhq",		"/d/city/lxs",
"/d/city/beidajie1",	"/d/city/qianzhuang",	"/d/city/eroad2",
"/d/city/guangchangnan","/d/city/guangchang",	"/d/city/guangchangbei",
"/d/city/guangchangxi",	"/d/city/jiangbei",	"/d/city/guangchangdong",
"/d/city/ximen",	"/d/city/chemahang",	"/d/city/pinqiting",
"/d/city/jiashan",	"/d/city/damingsi",	"/d/city/shangang"
});

void create()
{
	set("short", "��̲");
	set("long", @LONG
�����Ƕ���֮����һ��С��̲��������ȥ��һƬ�޼ʵĵ�ãã�󺣣�Զ��
����һ�ߣ�������������ֻ��Ÿ�ں��Ϸ��衣
LONG
);

	set("exits", ([
		"west" : __DIR__"daizong",
	]));

	set("outdoors", "̩ɽ");
	setup();
}

void init()
{
	object ob,me,name1;
	string where;
        
	me=this_player();
	if( ! (present("qiang fei", environment(me)) ) 
	&& me->query_temp("newbiejob2/start") 
	&& ! (me->query_temp("newbiejob2/middle"))) {
		message_vision(HIM "���󹦷�һ��С�����Զ���ĺ��濪�˹�����һ���������������˳�����\n"NOR,me);
		if (random(50) > 1) {
			message_vision(HIM "�����Ӵ�������ȡ��һ���ΰͣ���Ҫ�ݸ�$N��\n" NOR,me);
			ob=new("/d/sld/npc/qiangfei");
			where = escapename[random(sizeof(escapename))];
			name1 = me->query("id");
			ob->set_temp("name1",name1);
			new("/d/sld/obj/yanba")->move(ob);
			ob->move(where);
			me->set_temp("newbiejob2/middle", 1);
			message_vision(HIW "ͻȻ�ܳ�һ�����ˣ�һ�Ѵ��������������ΰͣ������ݳǵ�"HIR+where->query("short")+HIW"������ȥ��\n"NOR,me); 
		}
		else {
			message_vision(HIM "�����Ӵ�������ȡ��һ���ΰͣ��ݸ���$N��\n" NOR,me);
			new("/d/sld/obj/yanba")->move(me);
			me->set_temp("newbiejob2/middle",1);
			me->set_temp("newbiejob2/over",1);
			message_vision(HIM "$N�ӹ��ΰͣ��Ͻ������˻��\n"NOR , me);
		}
	}
}
