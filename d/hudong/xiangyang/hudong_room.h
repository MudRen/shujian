#include <ansi.h>
mapping skills;
string *sk;
int i;

void init(object me)
{
        object ob;

        mapping smap, pmap;   //����Ҫ��ֹ����npc û���书���� cigarman
            
        /*����ʱ���ж�������ڳ���lookʱ����������*/
        add_action("do_look", "look");

        /*������������ŵ�ʱ�����ʹ�ÿ�(kai)��������,���򿪳��ź󣬵�ͼ����ķ���npc�������
          ��ʼ�ĵ�ͼ����˫��npc��2M��һ���򿪳��ź��ڴ��͵�npc������Ƿ�����ս��Ҿ�����ߵ�copy*/
      add_action("do_kai", "kai"); 

       me = this_player();

       if( userp(me) && me->query_temp("��������/������ս/��Ӫ") && random(100) > 97 ) {
                   ob=new(__DIR__"npc/killer");
                  // ob->setparty(1,me->query("max_pot")-100,me->query("combat_exp"));
                   ob->set("combat_exp",me->query("combat_exp"));
                   ob->reincarnate();

                    skills = ob->query_skills();
                if (mapp(skills)) 
                {
                sk = keys(skills);
                for (i=0;i<sizeof(sk);i++)
                        skills[sk[i]] = this_player()->query("max_pot")-100;
                }
                  

                smap = ob->query_skill_map();
                pmap = ob->query_skill_prepare();
              if ( sizeof(smap ) && sizeof(pmap ) ){

                ob->move(environment(me));
                
                if(random(100) > 50) {
                ob->set("title",HIY"������ʿ"NOR); 
                ob->set_temp("��������/������ս/��Ӫ",1);
                }
                else{
                 ob->set("title",HIR"�ɹ��ȷ�"NOR); 
                 ob->set_temp("��������/������ս/��Ӫ",2);
                }
//                me->start_busy(1); 
                message_vision(CYN"$NͻȻ���˸�������ܾ��ñ������硣\n"NOR,me);
              }
                 else
                 destruct(ob);
      
        }
}

int do_look()
{
        object me = this_player();
        mixed *local;
        local = localtime(time() * 60);
        if(local[2] < 4 || local[2] >= 21) //����9�㵽�賿4��
        {
                write(BLU"    ս��������һҹ������������Ъ������������һƬ����֮�У�ż��ֻ����\n"
                         "��èͷӥҹ�ɰ�Ľ���������û�����������Ű�����"HIW"�ǹ�"BLU"������Ѭ����ڵĶ�\n"
                         "�ڲ�ԫ��Լ�ɼ�����ڰ��о�������������ɱ�������˲��ɵ�սս�������ҷ�\n"
                         "��һ˿һ����������\n"NOR, me);
        }
        if(local[2] >= 4 && local[2] < 8) //�賿4�㵽����8��
        {               
                write(CYN"    ����ĺ�ɱ����������������������ĿĻ�������һҹ����ɫ����������\n"
                         "�����ֵ���С��������Ժ���������˺������˵�ʬ�壬��Ѫ�ڵ�������Ŀ�ĵ�\n"
                         "���ʣ��𽥻����һ��"HIR"��ɫ"CYN"��Ϫ������������ݷҷ��Ŀ�����������Ѫ�ȵ�ζ\n"
                         "������Զ������������˫��ʿ��أ�Ժݶ������ϰ��֡�\n"NOR, me);
                        
        }
        if(local[2] >= 8 && local[2] <= 13) //����8�㵽����1��
        {
                write(HIG"    �����Ѿ�û���˴�սǰ����ò�����а����Ѿ���ɢ���˰�ȫ�ط���������\n"
                         "�������ս���ζ�����ȱȽ�����������ɱ���ˣ���������"HIR"��Ѫ����"HIG"�Ĳ�֫ʬ��\n"
                         "���˿����޲��ľ������������ཻ������ɱ�����ҽ����������������ǡ�\n"NOR, me);
        }
        if(local[2] > 13 && local[2] < 16) // ����1�㵽����4��
        {
                write(HIC"    �����������������ǣ�������ȥս���������Ȼû��ɢȥ����˼��˫����\n"
                         "��ɱ�����춯�أ����л������ű����û������Լ����ܻ��治ʱ�����ı�����\n"
                         "��Ȼ�����Žǳ�����������һ�δ�ٽ�����ʼ�ˡ�\n"NOR, me);
        }
        if(local[2] >= 16 && local[2] < 21) //����4�㵽����9��
        {
                write(HIB"    �����Թž��Ǳ��ұ���֮�أ�ʱ������Ҳ�����⣬�ɹŴ��������ս����\n"
                         "����ʿ�����سǣ�˫��������ˣ�����������ǿ����ȴҲ�ѷ��壬Ѫ����ζ\n"
                         "���Ϻ�ʬ��ص��龰���������鲻ס�Ŀ����š�\n"NOR, me);
        }
}

int do_kai(string arg)
{
        object me = this_player();
        object ob = new("/d/hudong/xiangyang/npc/killer");
        object room;
         
        if(arg != "����") return notify_fail("��Ҫ��ʲô��\n");
          
        if(!objectp(present("dasong yishi", environment(me)))&&objectp(room=load_object("/d/hudong/xiangyang/xuanwumen"))){
           ob->move(room);
           tell_object(me, HIY"������������ű���Ҫ�򿪳��ţ��������һ�˴�ס��....\n"NOR);
           COMBAT_D->auto_fight(ob, me, "aggressive");
          return 1;
          } 
           return notify_fail("������ȫ�ǵ�������ʱ�俪���ţ�\n");
           
          
     
}

int valid_leave(object me, string dir)
{     
        if( userp(me) && !me->query_temp("��������")){
        tell_object(me,"�Ƿ����븱����ϵͳ�Զ������\n");
        me->move("/d/city/guangchang");
       me->delete_temp("title");
       me->remove_all_killer();
       me->dismiss_team();
       me->clear_conditions_by_type("poison");
       me->clear_conditions_by_type("hurt");
       me->clear_conditions_by_type("busy");
       me->clear_condition("killer"); 
       me->delete_temp("kill_other");
       me->delete_temp("other_kill");
       me->clear_condition("job_busy");
        return notify_fail("");
        }
         return ::valid_leave(me, dir);
}

