// cj1.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ƽ�����ڵ�һ�����֣�·���������������ַǷ�����Ϊ�˵غ����½�
��̳��ľ����ȥ��Զ�����Գ������Ķ�����������ϱ���һ��С�Ե꣬������
����ʳ���ںȾƲ�ȭ��
LONG
        );
        set("exits", ([ 
          "west" : __DIR__"cj1",
          "northeast" : __DIR__"cj3",
          "south": __DIR__"xchidian"
]));
        set("outdoors", "ƽ����");
        setup();
}

