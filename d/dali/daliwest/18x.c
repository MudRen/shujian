// Room: /d/dali/18x.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "ʮ��Ϫ");
	set("long", @LONG
ʮ��ϪҲϪϪ�������ɱ�������Ϊ��ϼ�ơ��򻨡���Ϫ��ãӿ����Ϫ����
Ȫ����ʯ��˫ԧ�����ɡ�÷Ϫ����Ϫ����Ϫ��������Ϫ����̡�Ī�С�����
�����ϡ���ЩϪˮ���е�Դ�ڻ�ѩ�������ʣ��е�����ȻȪˮ���������ס�
���������������ע�������
LONG
	);
        set("outdoors", "����");

	set("exits", ([
                "southwest" : "/d/tls/diancang",
	]));

	setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/18x",1);
      }
}
