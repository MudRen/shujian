// Room: /city/lichunyuan2.c
// Dec.12 1997 by Venus
inherit ROOM;
void create()
{
        set("short", "����Ժ��¥");
        set("long", @LONG
��վ������Ժ��¥���������������첻�����ơ����õľ��Ծ��µ�
���ϵ��£�ͻȻ�������Ī�����ջ�ͳ嶯��
    �������������ǧ�������ڵ��ֶ����㣬���뵽���ǿ��ܾ�������
�����е��۸��ڶ�����ʱ��Ϊ���ġ�
LONG);
        set("exits", ([
            "down" : __DIR__"lichunyuan",
        ]));

        setup();
}

//�Ǿ���
int is_mirror() { return 1; }