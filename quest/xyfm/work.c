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
        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongmen",
]));

        setup();
}

//�Ǿ���
int is_mirror() { return 1; }