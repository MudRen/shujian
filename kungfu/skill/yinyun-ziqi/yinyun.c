//yinyun.c
//by snowman@SJ 03/06/99

#include <ansi.h>

string exert_name(){ return HIG"���ھ�"NOR; }

int exert(object me)
{
        int skill;

        if (!me->is_fighting())
                return notify_fail("�������ս���в����������ھۡ�\n");
        if (me->query_temp("yinyun"))
                return notify_fail("�������������ھ��ˡ�\n");

        if (me->query_skill("yinyun-ziqi",1) < 180
            || me->query_skill("force",1) < 180
            || me->query_skill("taoism",1) < 180 )
                return notify_fail("����Ŀǰ����Ϊ���������������������ھۣ�\n");

        if (userp(me) && me->query_skill_mapped("force") != "yinyun-ziqi")
                return notify_fail("����ڹ����ԣ���������ʹ�������ھۡ���\n");                                                                                     
        if (userp(me) && me->query_skill_mapped("cuff") != "taiji-quan")
                return notify_fail("̫��֮�����ھۡ����ϱ����ڼ���̫��ȭ������²���ʹ�á�\n");
                
        if (me->query("max_neili") < 2500)
                return notify_fail("���������Ϊ�����������ھ����裡\n");
                
        if (me->query("neili") < 500)
                return notify_fail("������������������ھ����裡\n");

        skill = me->query_skill("yinyun-ziqi", 1) + me->query_skill("taoism", 1);

        tell_object(me, HIW "\n��Ĭ���ڹ����������������ļ��޷��ӳ������ھ���ת���ؿڴ�Ѩ֮�ϣ�ȷ������������\n" NOR);
        message_vision(MAG"\n$N��һ�ڡ���������������Ϣ��ת��ȫ����֮�У����Ͻ����Գ���ɫ�����⣡\n\n" NOR, me);
if(me->query("quest/wdjiuyang/pass")) {
                                     me->set_temp("title",HIR"̫����ʦ"NOR);
                                  me->set("title",HIR"̫����ʦ"NOR); }


        me->set_temp("yinyun", skill);
        
       if(random(me->query("kar"))>=15 && !me->query("quest/wdjiuyang/pass") ){
       	                      me->set_temp("quest/wdjiuyang/pass",1);
                message_vision(HIW"$N�ƺ�������һ˿�书������˸յ���������ʹ������������ˮ�������ޱȡ�\n"NOR, me);               
                       }
      
       if( time()-me->query("char_check") > 86400
            && me->query("kar") <31 
            && me->query("int")>=35
            && !me->query("quest/wdjiuyang/pass")
            && random(me->query("kar")) >=28
            && random(15)==1)
             { 
                                      me->set("quest/wdjiuyang/pass",1);
                                      me->set_temp("title",HIR"̫����ʦ"NOR);
                                      me->set("title",HIR"̫����ʦ"NOR);
                     message_vision(HIR"$N�͵����Ȼ��ͨ�������̫���书������˸յ������̲�ס���쳤Ц����\n"NOR, me);
 
 
 
 
            log_file("quest/wd9y",sprintf("%-18s�ɹ������䵱��ɣ�����%d����%d������%d��\n",
                     me->name(1)+"("+capitalize(getuid(me))+")",
                     me->query("kar"), 
                     me->query("int"),
                     me->query("pur")  ), me  );            

      }
       	
       	
       	

        call_out("checking", 1, me);
        me->add("neili", -300);
     if(me->query_skill("yinyun-ziqi",1)<=350 )  
     	                  me->start_busy(random(2));
        return 1;
}

void checking(object me)
{
        if ( !me ) return;
        
        else if (me->is_ghost() || !living(me)){
                me->delete_temp("yinyun");
                }
        
        else if (!me->is_fighting() || me->query("neili") < 500 || me->query_temp("yinyun") <= 0 ) {
                message_vision("\n$N�³�һ�����������ϵ���ɫ������Ҳ������ʧ�ˡ�\n\n", me);
                me->delete_temp("yinyun");
me->delete_temp("quest/wdjiuyang/pass");
        }
	
        else if((me->query("eff_qi") < me->query("max_qi")/4*3) && me->query_temp("yinyun")){
        	me->add("neili", -50);
                me->receive_curing("qi", (me->query_skill("medicine",1)/3*2) + 10);
                me->add_temp("yinyun",-1);
                message_vision("$Nȫ���Ϲ����������˿ڴ�����Ѫ�Զ�ֹס�ˣ�\n", me);
                call_out("checking", 3, me);
        }
        
        else call_out("checking", 3, me);
        return;
}  

int help(object me)
{
	write(HIM"\n�����������ھۡ���"NOR"\n");
	write(@HELP
	һ���ܼӣ�Ӭ�治���䣬�˲�֪�ң��Ҷ�֪�ˡ�Ӣ�������޵У��ǽ��ɴ�
	����Ҳ�����ھۣ�������һ�����������˵���һ��Ҳ��
	
	Ҫ��	�ڹ��ȼ� 180 ���ϣ�
		�������ȼ� 180 ���ϣ�
		��ѧ�ķ��ȼ� 180 ���ϣ�
		������� 2500 ���ϣ�
		���� 500 ���ϡ�
           ��һ������"��ʱ"�����䵱������Բͨ���ķ�Ч����
		��һ�����ʿ��������䵱������Բͨ���ķ����С�
		
		
		
HELP
	);
	return 1;
}

