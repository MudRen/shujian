inherit ROOM;

void create()
{
	set("short", "�����");
	set("long",@long
�سʳ����Σ�שʯ�ṹ�����е������¥Ϊ�½�������صش�ˮ½Ҫ���
��¥���ȿ����������ܷ�����������ԫ���˺ӡ�ʯ������ɵ����Ϲ��£���
ʱ��Ϊ�˷����ϵֿ����ŵ����ܡ�
long);
	set("outdoors", "����");
	set("objects",([
		NPC_D("guanfu/wujiang") : 1,
		NPC_D("guanfu/bing") : 2,
	]));
	set("exits",([
                "south" : __DIR__"fengqiao",
                "north" : __DIR__"nanlin",
       ]));
	setup();
}
