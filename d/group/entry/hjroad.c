// road1.c С·

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
����С·�ǵ����������ȥ���������ʱ�߳����ģ��������߾͵���ԭ��
Ե������ɭ���ˡ�ż����������Զ������Ұ�޵ĺ������㻹�ǿ��ȥ�ɡ�
LONG
        );

	set("group", 1);
        set("exits", ([
		"westup" : "/d/hj/shanqiu",
		"east" : "/d/hj/pmchang",            
        ]));

        set("outdoors", "�ؽ���ԭ");
        
	setup();
}
