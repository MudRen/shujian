// Room: /d/putian/mtd1.c

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
��ͷ��������ɹ����ĺ󱳡���ǰ��һ��Ƭ����أ���������Լ���Կ�����
�����Ʋ�ñ�����Ա���һƬ��ѹѹ�����֣���ľ�߸߰��������Ǻ����롣��ͷ�Ŀ�
���ϣ���һ��ɮ������վ�Ų�����
LONG
        );

        set("exits", ([
                "northup" : __DIR__"mtd2",
//                "westdown" : __DIR__"shanlu5",
        ]));
        set("objects",([
                CLASS_D("putian") + "/yuanhui" : 1,
        ]));

        set("outdoors", "����");
        setup();
}

