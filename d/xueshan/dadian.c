 // dadian.c �����

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","�����");
        set("long",@LONG 
������ѩɽ�����´���Ȼ��Զ��ѩɽ�����������ȷ����ԭҲ�ѵ�һ
�������洣��һ����ʮ�߸ߵĽ����𣬴�����������Ƽ����������������
�������⻹�������н�����ô��������������һյ�����ƣ�һ�����˳���
���˶�Ҫ���ڴ˹���(gongfeng)���͡��������������ȡ��ƹ���𣬿����ߵ�
ȴ�յ�ȥ��
LONG);
        set("exits",([
                "north": __DIR__"queridian",
                "southdown":__DIR__"guangchang",
                "westdown" : __DIR__"huilang3",
                "eastdown": __DIR__"huilang4",
        ]));
        set("objects", ([
         CLASS_D("xueshan") + "/lingzhi" : 1,
         __DIR__"npc/xiangke" : 2,
        ]));
        setup(); 
}
void init() 
{ 
         add_action("do_gongfeng", "gongfeng");
}
 
int do_gongfeng()
{
          object ob, me;
          mapping fam; 
          int i, j,z;
        
          me = this_player(); 
           fam = me->query("family"); 
                   i = (int)me->query("age");  
                   j = (int)me->query("xs_gf");
                  z  = (int)me->query("xs_number");

          if( !(ob=present("su you", me)) )
           return notify_fail("����Ҫ�����Ͳ����ڴ˹��\n"); 

                if (fam && fam["family_name"] == "������"){
                if ( (int)me->query_skill("huanxi-chan", 1) < 90 ){
                            if (i != j && z <12){
                 me->add("xs_number",1);
                destruct(ob);
                message_vision("$N���е����ж��������ԣ��ӻ����ó�һ�����ͣ������˳����������������ˣ�\n", me);
                return 1;
                }
                             if ((z ==12)&&(i==j)){
                             me->add("gf_ok",1); 
			     me->set("xs_gf",i);	
                             me->delete("xs_number");
                message_vision("$N���е����ж��������ԣ��ӻ����ó�һ�����ͣ������˳����������������ˣ�\n", me);
                            write("������ĬĬһ�㣬����Ĺ����Ѿ����ˣ�\n", me);
                            destruct(ob);
                return 1;
                }
                            if( (j != i) && (z == 12 ) ){
                            message_vision("$N���е����ж��������ԣ��ӻ����ó�һ�����ͣ������˳����������������ˣ�\n", me);
                            write("������ĬĬһ�㣬����Ĺ������Ѿ����ˣ�\n", me);
                             me->add("gf_ok",1); 
			     me->set("xs_gf",i);	
                             me->delete("xs_number");
                        destruct(ob);
                return 1;
                }
                            }
                else
                message_vision("$N�ӻ�������һ�����ͣ������˳����������������ˣ�Ȼ�������Ц��Ц��\n", me);
                destruct(ob);
                return 1;
                }  
                message_vision("$N�ӻ�������һ�����ͣ������˳����������������ˣ�\n", me);
                destruct(ob);
	             return 1;
}
