//qiant.c
//Csl 2000.04.26

inherit ROOM;
void create()
{
        set("short","ǰ��");
        set("long",@LONG
����Ѧ����ǰ���������޽������Զ������������Ϊ�¾ɣ�������߳���
��ȫû�г����լ������֮����������һ����ܣ�������Ŀ��ȫ�Ǹ���ҽ�飬
һ����֪����������˶�ҽѧ�����о���
LONG
        );
        set("exits",([
		"south"  :  __DIR__"xue_men",
		"north"  :  __DIR__"tjing",
	]));
	setup();
}
