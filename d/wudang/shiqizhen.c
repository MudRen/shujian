// shiqizhen.c ʮ����
// By Spdierii@ty ����yttlg quest
#include <ansi.h>
inherit ROOM;
string look_caocong();
string look_dache();
void create()
{
        set("short", "ʮ����");
	set("long", @LONG
�������䵱ɽ�¶��������ʮ������һ��ɽ���˼�ϡ��,��Щ������
����һ����(dache)����ĵ����ڲݴ�(caocong)֮��,͸¶��Щ�Ź֡�
LONG
	);
	set("item_desc",([
		"caocong"	:	(: look_caocong :),
              "dache"       :      (: look_dache :),
	]));
       
set("exits", ([
                "out" : __DIR__"wdroad6",
                        ]));





setup();
}
void init()
{    
        object me = this_player();

       if (me->query_temp("quest/yttlg/story")){
       add_action("do_bo", "bo");
	add_action("do_get", "get");
  }
}

string look_dache()
{
     	
  	return "��������������ͷ�����飬�Խ����ѣ����ڵ���,��״���ҡ�  \n";
}
string look_caocong()
{
     	
  	return "ȴ��������һ�˸�������Ҳ������������ȥ��ʱ��\n";
}
int do_bo(string arg)
{      
        object me = this_player();
        
        if ( !arg || arg != "����" )
                return notify_fail("��Ҫ��ʲô��\n");
       
        message_vision("$N��������������������ȥ���ƺ�Ӱ������ʦ������ң���æ��۱���\n"
                       "ֻ����˫Ŀ���գ������ֽ����ɫ���ǿɲ����㲻�ɵ��־���ʹ,�����\n"
                       "������ȥ�����������ϣ��е�����΢��,���´�ϲ�����������ؿڣ�����\n"
                       "��һ�������ڻ���������ֻ��ʱͣʱ����˵������ʱ����ֹЪ,���ɴ���\n"
                       "��ޡ��ּ���˫��˫�������£�ԭ����֫�ǽڶ��ѱ����۶ϡ�����ָ��\n"
                       "����ǡ��۹ǡ��ȹǵ���ð����Ѫ�����ǵ������ֲ��ã���������һ�۶�\n"
                       "������֮������ʵ���˲Ҳ��̶á�\n", me);
         return 1;

}
int do_get(string arg)
{      
        object me = this_player();
        
        if ( !arg || arg != "�����" )
                return notify_fail("��Ҫ��ʲô��\n");
       
        message_vision("$N����ŭ���ģ�Ŀ�����ѣ�֪��������ȥ���ã�ƾ�Ž������������׷�ϵ���\n"
                       "��ŭ֮�£�������ȥ���գ����漴����:����������̣�����Ⱦ�������Ҫ������\n"
                       "�ӱ���ʮ��δ���������ȵĽ����������У�չ���Ṧ����ɽ�ϼ��С�\n", me);
        me->move("/d/wudang/houyuan");
        me->set_temp("quest/yttlg/story1",1);
        me->delete_temp("quest/yttlg/story");
        return 1;

}

