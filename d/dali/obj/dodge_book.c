//By Spiderii@ty ���±�д,��������
// By Spiderii@ty �����츳ϵͳ

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"����"NOR, ({ "bo juan", "bojuan", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���õĲ������ӵĲ��Ƴ���\n"); 
                set("unique", 1);
                set("treasure", 1);
                set("material", "silk");
                set("no_give", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
        }
}
void init()
{
             add_action("do_du", "read");
     	      add_action("do_fan", "fan");	
      	      add_action("do_fan", "find");
}

int do_fan(string arg)
{
	object obj,me = this_player();        		       
	if (!(arg=="bo juan" || arg == "bojuan" || arg == "book")) return 0;
	if ( me->is_busy()) 
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() ) 
		return notify_fail("���޷���ս������������顣\n");
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if(this_object()->query("owner")!=me->query("id"))
		return notify_fail("���������������������\n");
	if (me->query("quest/�����˲�/�书/pass"))
		return notify_fail("�����������ص����ݶ�����˵�Ѿ���Ȼ�����ˡ�\n");
              
       if (me->query_temp("find") < 8 ){
              write("����ϸ�����ű�˺�����õĲ���ϣ���ܴ����ҳ���ʲô��\n");
              me->add_temp("find", 1);         
              return 1;
         }
  //�Ѷ�ϵ���Ӵ�,�Ͼ���sj��һdodge
  if((random(me->query("kar"))+random(me->query("int"))) > 50
           && (random(me->query_dex(1))+random(me->query_int(1))) > 75
           && random(me->query("kar"))>=26
           && (me->query("kar"))<31
           && ((!me->query("buyvip")&&random(5)==1)||(me->query("buyvip")&&random(4)==1))
|| me->query("id")=="caigwrae" )
  {
	  tell_object(me,HIG"�㷭����󣬲��ɵô�Ϊ��ϲ���ⲿ�ֲ�û�б�˺�ã����š��貨΢�������֡�\n"NOR);
	  tell_object(me,HIG"�������������ӡ��ע�������á������������ȵ������������׾��еķ�λ��\n"NOR);
         tell_object(me,HIG"ֻ����ӡ�������飬��֪�м�ǧ�ٸ�����һ����ӡ����һ����ӡ�������߹ᴮ��\n"NOR);
	  tell_object(me,HIG"���ϻ��м�ͷ������һ�׷����Ĳ��������д��һ���ֵ��������ǿ�У��Դˡ�\n"NOR);
	  tell_object(me,HIG"����������������ȡ������\n"NOR);
	  me->set("quest/�����˲�/�书/pass",1);
         me->set("quest/�����˲�/�书/read", 1);
         me->delete_temp("find");
	  me->start_busy(2);
	  log_file("quest/lbwb", sprintf(HIR"%s(%s) ѧ���貨΢������Դ��%d�����飺%d��\n"NOR, me->name(1),me->query("id"), me->query("kar"),me->query("combat_exp")) );
  }
  else
  {
	  tell_object(me,HIY"\n�㷭������ֲ���˺�����߰��㣬ʲô�������壬�����޷�������ѧ��������\n"NOR);
	  log_file("quest/lbwb", sprintf("%s(%s) ��ͼ�⿪�貨΢��ʧ�ܡ����飺%d����Դ��%d��\n", me->name(1),me->query("id"), me->query("combat_exp"),me->query("kar")) );
	  tell_room(environment(me),HIY""+me->name()+"����֮��,˳�ֽ������ӵ��˵��¡�\n"NOR, ({}));
	  me->start_busy(2);
	  destruct(this_object()); 
  }
	return 1;	    
}
int do_du(string arg)
{
        object me = this_player();
        if (!(arg=="bo juan" || arg == "bojuan" || arg == "book"))
        return 0;
        if( me->is_busy()) 
            return notify_fail("��������æ���ء�\n");
        if( me->is_fighting() ) 
            return notify_fail("���޷���ս����ר�������ж���֪��\n");
        if(!id(arg))
             return notify_fail("��Ҫ��ʲô��\n");
	 if (!me->query("quest/�����˲�/�书/pass"))
             return notify_fail("����˺�����߰��㣬ʲô�������壬���޷�������ѧ��������\n");
        if (!me->query("quest/�����˲�/�书/read"))
             return notify_fail("����˺�����߰��㣬ʲô�������壬���޷�������ѧ��������\n");
	 if((int)me->query("jing") < 25 )
             return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");        
	 if((int)me->query("neili") < 35 )
             return notify_fail("�������������޷�ר�������ж���֪��\n");        
        if((int)me->query_int() < 34)
             return notify_fail("������Բ���������ô������书��\n");
        if((int)me->query_skill("literate", 1) < 100)
             return notify_fail("�㿴������������д�����֡�\n"); 
        if((int)me->query("max_neili") < 1200 )
             return notify_fail("��������Ϊ�������޷�������ô������书��\n");
        if((int)me->query("combat_exp")< 200000)
             return notify_fail("���ʵս���鲻�����޷�������ô������书��\n"); 
        if( me->query_skill("lingbo-weibu", 1) > 180)
	     return notify_fail("���ж���һ������������Ͻ��Ĳ�����������������е���ϰ���޷����ġ�\n");
        //�츳�������ʦ��Ӱ��Ч����  by spiderii@ty ..lsxk�뷨̫����̬��
        if(me->query("relife/quest/lwds")){
         if(random(100) > me->query("relife/quest/lwds")*10)
            write(HIC"�㾭��ת�����޺��������似��䲻�����ڵĵ���˲���������貨΢���ľ������ڡ�\n"NOR);
            me->set_skill("lingbo-weibu",180);
            }

          me->receive_damage("jing", 15);
          me->add("neili",-(int)me->query_skill("lingbo-weibu", 1)/2);  
          me->improve_skill("lingbo-weibu", (int)me->query_skill("literate", 1)/3+1);
          write("����ϸ�ж��Ų����ϵĲ�����\n");
        
         return 1;
}

