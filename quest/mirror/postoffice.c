// Room: /d/system_3/postoffice.c
inherit ROOM;
void create()
{
        set("short", "������վ");
        set("long", @LONG
�����Ǹ������ݳǹٸ�����Ͱ��յ��ż��շ�����վ����վ���ſ���
����һ��ľ��(sign)������д��Щ�֡�
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "������֪��֮����Ϊ�����ż��շ����ң������ҷ����գ�\n"
           "�����ʼ�һ������շ�����������ask officer about mail��\n",
]));
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"beimen",
        ]));

        setup();
}

//�Ǿ���
int is_mirror() { return 1; }