inherit ROOM;
int do_drop(object me, object obj);
string money_str(int count);
void create()
{
        set("short", "������");
        set("long", @LONG

����ǰ����һ��˶��������ѡ����������ݳ������ķ���ѻ�����
�л�����ʶ�ĺ�����ң�������������ӷ�����ǰ�������(drop)
����������

LONG
        );
        set("exits", ([
                 "up" : __DIR__"guangchang",
        ]));

        setup();
}
//�Ǿ���
int is_mirror() { return 1; }