// work.c modified by system_3

inherit ROOM;

int cot;
void create()
{
        set("short", "�ƾ��ֹ���");
        set("long", @LONG
������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
        );

        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ximen",
]));
        set("item_desc", ([
                "sign": @TEXT
��������ȱ���֣������Ӷһ���̹����ɻ
work     ��ʼ������
TEXT
        ]) );

        setup();
}
//�Ǿ���
int is_mirror() { return 1; }