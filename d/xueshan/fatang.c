// Room: fatang.c

inherit ROOM;

void create()
{
	set("short", "���ȷ���");
	set("long", @LONG
�����������ܿ�������ľ�ṹ�����滷�����ȣ���������ƽ����������տ��
���ɱ��¡����»����ų����ɰأ�ͥ�и���һ�꼸���ֵİ���÷������������
���������Ծ�ͦ�Ρ�
LONG
	);

	set("exits", ([
		"up" : __DIR__"fatang2",
		"south" : __DIR__"fanyinge",
	]));
        set("objects", ([__DIR__"npc/zayilama" : 1,]));
	setup();
}
int valid_leave(object me, string dir)
{
        if ((string)me->query("family/family_name") != "������" 
           && dir == "up"  
           && present("zayi lama", environment(me)))
	return notify_fail(
"����������ס���㣬С������ص�����ʩ�����������·����������ޣ���������ʩ��\n
�Ƿ���������ݼ���\n");

	return ::valid_leave(me, dir);
}
