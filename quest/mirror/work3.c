// work.c modified by system_3

inherit ROOM;

int cot;
void create()
{
        set("short", "����ӹ���");
        set("long", @LONG
����һ�����ӹ����������ǹ����ѿǳ��׵ĵط����׳��ϰ���һ
��һ����֪����ʮ�־����ĸ��ݵ������ˣ����Ǵ���һ����Ц�������
�������������ææµµ�Ĺ����ţ��ſڹ���һ������(sign)��
LONG
        );
        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
   "east" : __DIR__"nanmen",
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