// �������䣬�ٺ�
// by Looklove 2001/11/12

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��Ϣ��");
	set("long",@long
�������������Ѿ����ڣ��������޷����������������ֵ���������
���������Ĳ�����Ϸ���뾡�����ѡ��������ݿɲ���������š�
long);
	set("outdoors", "����");
	set("no_update", 1);
	set("no_fight", 1);
	set("no_save", 1);
	set("exits", ([
		"������ջ" : "/d/city/kedian",
		"����㳡" : "/d/city/guangchang",
		"����ͤ"   : "/d/city/yuelaoting",
		"������"   : "/d/city/chmiao",
		"���ǰԺ" : "/d/wuguan/dayuan",
		"̩ɽ����̨"   : "/d/taishan/fengchan",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me)) {
		message_vision("$N��"+query("exits/"+dir)->query("short")+"�ķ�����ȥ�����˰��죬�����Լ�����ԭ�ء�\n", me);
		me->add_busy(1);
		return 0;
	}
	return ::valid_leave(me, dir);
}
