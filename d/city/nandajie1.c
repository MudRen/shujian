// Room: /d/city/nandajie1.c

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
������һ�������Ľֵ��ϣ����ϱ���ͷ���졣�ϱ����ϳ��ţ�����ͨ����
���ģ��������߸���һ��С԰�ӡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"south" : __DIR__"nanmen",
		"west" : __DIR__"geyuan",
		"north" : __DIR__"nandajie2",
		"east" : __DIR__"xiaopangu",
	]));
      
	setup();
}
