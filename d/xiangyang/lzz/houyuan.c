//houyuan.c
//Csl 2000.04.26

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long",@LONG
������Ѧ������Ժ����ɨ�ķǳ��ɾ�����������ķ��ż������Ρ�������
һ����԰����ֲ�Ÿ��ֻ��ݣ��ϱ��ǲ��ȡ�
LONG
        );
	set("outdoors", "����");
        set("exits",([
		"north"   :  __DIR__"huayuan",
		"south"   :  __DIR__"chelang2",
	]));

	setup();
}
