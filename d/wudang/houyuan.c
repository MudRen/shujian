// houyuan.c ��ɽСԺ
// By Spiderii@ty ����yttlg quest
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ɽСԺ");
	set("long", @LONG
���Ǻ�ɽ��һ��СԺ�����ü�򵥵�������һ����һ����һ�Ρ�һ���ţ�
��Ҳû�б��ʲ��Ƚ�����עĿ����ǽ�Ϲ���һ�ѽ�����������䵱��ɽ��
ʦ��������������ڡ�
LONG
	);

	set("exits", ([
                "north" : __DIR__"yuanmen",
	]));

	set("cant_hubiao", 1);

	set("objects", ([
                CLASS_D("wudang")+"/zhang" : 1 
        ]));

        create_door("north", "����", "south", DOOR_CLOSED);
        setup();
}
void init()
{
  object me=this_player();
  if (me->query_temp("quest/yttlg/story1"))
  {
     tell_object(me,HIW"�㱼����������ǰһ�������������е�����ʦ����ʦ�������������������������˰��㡭��\n"NOR); 
     tell_object(me,HIW"���������ͽ�˳����ģ�������д��𣬵��²�Ͼѯ�ʡ���������ȡ��һƿ���׻�����������\n"NOR);       
     tell_object(me,HIW"��ƿ�ڱ��ð�����ס����ʱҲ����������ƿ��������ָһ�󣬴�ƿ���ѣ�ȡ��������ɫ��ҩ��\n"NOR); 
     tell_object(me,HIW"�������֪����ʧ�����ﻹ�����ʣ���\n"NOR);       
     tell_object(me,HIW"������˫��ʳָ��Ĵָ���ã��ɡ����쾢���ƣ���ʳָָ���������Ҷ��������ִ��ġ���Ծ�ϡ�\n"NOR); 
     tell_object(me,HIW"������ʱ�������⡰���쾢����Ծ�ϡ�ʹ�������������¶���֮��Ҳ�ܻ���Ƭ�̣�������ֱָ�ڵ���ʮ�£���������Ƕ�Ҳ������\n"NOR);       
     remove_call_out("liaoshang");
     call_out("liaoshang", 10, me);         
  }
        add_action("do_linmo", "linmo");    

}
void liaoshang(object me)
{
  if(!me) return;

   tell_object(me,HIW"\n����������̾�˿�����˫����ɽ������������£�����˫ȡ����ҡ��ճ�Ѩ����\n"NOR); 
   tell_object(me,HIW"\n�ǡ��ճ�Ѩ�������������ؽ��յĽ��֮�������������ֵ���������������ϡ�\n"NOR);
   tell_object(me,HIW"\n�������֣�һ��һ���������任��������ʮ����ʱ������������ſ��˿�,��������ҩ������С�\n"NOR); 
   tell_object(me,HIW"\n��һֱ���ĵ�������ʱ��������һ�����Ž��˳�����\n"NOR);
   tell_object(me,HIW"\n������Һ�ͷ���⽩Ӳ����ҩ�����ʺ�ȴ���������㲻�ɵ����ְ�Ħ����ͷ���⡣\n"NOR); 
   tell_object(me,HIW"\n�������漴��ָ��������Ҽ�ͷ��ȱ�衱�����Ḯ����Ѩ��β���ġ����ء��������š���Ѩ��������ת֮�󣬲�������֫��ʹ�����ֻ��ԡ�\n"NOR);
   remove_call_out("liaoshang1");
   call_out("liaoshang1", 10, me);      


}
void liaoshang1(object me)
{
  if(!me) return;
   tell_object(me,HIW"\n��ʱ���洫�����������ݼ�������,�㲻��ŭ����ͷ,˵��:������˹,������ʦ�硣\n"NOR); 
   tell_object(me,HIW"\n������ڰ��ֵ�:Ī��,�����վ�Ҫ�ʸ�ˮ��ʯ���ġ����ҽ���������\n"NOR); 
   tell_object(me,HIW"\n��ǿѹסŭ��,����������˽���,������û���ϸѯ�������������������\n"NOR);  
   tell_object(me,HIW"\n�����˵���,�����᲻�ɵĳ�̾һ��:���������ټ�����,�Ӵ����Ƕ���֮���ˡ�\n"NOR);
   tell_object(me,HIW"\n��������������Ɑ�پ�Ҳ�����ٺ��ˡ�һ����֮�󣬽�����λʦ�ֵ��������\n"NOR); 
   tell_object(me,HIW"\n������˵��:����������Σ�ʦ�ֵ�Ҳ�ɺ����ټ���һ�档��˵�����������Ȼ��\n"NOR);
   tell_object(me,HIW"\n���������һ��,˵��:�������°ɡ�\n"NOR); 
   me->delete_temp("quest/yttlg/story1");
   me->set_temp("quest/yttlg/story2",1);
}
int do_linmo(string arg)
{
        int improve, cost, lv;
        object me = this_player();
        
        improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);
        improve /= 2;
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
         	
        if (arg == "����" ){             
            	if(!me->query("quest/yttlg/pass") || !me->query_skill("yitian-tulong", 1))  
               		return notify_fail("������ġʲô?\n");
      if( me->query_skill("yitian-tulong", 1) == 100 )
                            return notify_fail("���Ѿ��������������ڻ��ͨ��!\n");
        	cost = 600 / (int)me->query("int");
        	cost = 600 / (int)me->query("int");

    	if ((int)me->query("jingli") < cost || (int)me->query("jing") < cost){
                	message_vision("$N�ķѾ�����ȣ�һ�����˹�ȥ��\n",me);
                	me->unconcious();
                	return 1;
                } 
	if ( me->query_skill("yitian-tulong", 1) > 99 ){
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        lv = me->query("max_pot")-100;
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲�������������������ľ������ڡ�\n"NOR);
            me->set_skill("yitian-tulong",lv);
            }

      }
              message_vision("$N��ָ�ڿ��в�ͣ�ıȻ�,һ��һʽ,���󾡼����ġ�\n"NOR, me);  
           	me->improve_skill("yitian-tulong", improve);            
           	me->receive_damage("jing", cost, "���Ĺ���");
           	me->receive_damage("neili", cost/2, "���Ĺ���");
           	me->receive_damage("jingli", cost, "���Ĺ���");                        
           	return 1;
        }     
        return 0;
}

