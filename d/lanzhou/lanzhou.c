
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һ��ǣ����������ľ������ģ�Ҳ���Ļ����ġ����ݵ��Ļ�������
��ɣ����д�ͳ���͡�����������Ӱ�죬Ҳ�лؽ̵�ͶӰ�����𾩳ǡ����ݣ�
ϸ�����в��㣬������֮��ȴ�й�֮��
LONG);
        set("outdoors", "����");

        set("exits", ([
                "west" : __DIR__"lanzhouw",
                "south": __DIR__"lanzhous",
                "east" : __DIR__"lanzhoue",
        ]));
        
	setup();
}
