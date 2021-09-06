// Lingwu.c 
// Created by snowman@SJ 25/09/2000
// By lsxk@hsbbs  �����츳Ӱ��Ч��  2008/3/14

#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_SAVE;

int start_lingwu(object me);
int halt_lingwu(object me);
int help(object me);

#define PLACE_LOG       LOG_DIR + "static/lingwu_places"

mapping lingwu_places = ([ ]);
string query_save_file(){       return PLACE_LOG;       }
mapping query_stuffs(){ return lingwu_places;   }

void create()
{
        if( !restore() && !mapp(lingwu_places) )
                lingwu_places = ([]);
}

void clear_all()
{ 
        if (previous_object() && getuid(previous_object()) != ROOT_UID ) return;
        lingwu_places = ([]); 
}

/*
void remove()
{
        if(lingwu_places) lingwu_places = ([ ]);
        
        
        save(); 
}
*/

int main(object me, string arg)
{
        object room;
        mapping lw_skill;
        string special, str;
        int basic_lvl, special_lvl, i, cnt = 1;
        
                
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("����æ���أ���ЪϢһ��������ɡ�\n");
       
        if( !arg ) return notify_fail("��Ҫ����ʲô��\n");
        
        if( sscanf(arg, "%s %d", arg, cnt) != 2 )
                return notify_fail("��ʽ�� lingwu <����> [����]\n");
        if( cnt < 1 ) 
                return notify_fail("����[����] ������ڻ���� 1 ��\n");
        
        basic_lvl = me->query_skill(arg, 1);
        
        if( !basic_lvl )
                return notify_fail("�㲻�����ּ��ܡ�\n");
               
        if( basic_lvl < 100 )
                return notify_fail("���"+to_chinese(arg)+"��û�������Լ�����ľ��磡\n");
                        
        if( (int)me->query("potential") < 1 || (int)me->query("potential") < cnt ) 
                return notify_fail("������ҪǱ�ܣ�����Ŀǰ��Ǳ�ܲ�������"+chinese_number(cnt)+"�����衣\n");
                
        if( me->query("jing") * 100 / me->query("max_jing") < 80 )
                return notify_fail("��Ŀǰ����ƣ�ͣ����ʺ�������ѧ��\n");
                
        if( !objectp(room = environment(me)) )
                return notify_fail("�˵�������Ʈ��䣬�㻹�Ǳ������˰ɡ�\n");
        
        if( !mapp(lw_skill = room->query("lingwu")) )
                return notify_fail("�˵���ʲ�ر�֮������ʲô������ģ�\n"); 
                       
        special = base_name(room);
        if( stringp(special) ){
                /* Get the special skill in room  */
                if( !mapp(lingwu_places[special] ) )
                        lingwu_places[special] = lw_skill;
                else if( lingwu_places[special] != lw_skill ){
                        log_file("static/lingwu_place_changed", sprintf("%s changed! Skill %s -> %s�� Up %d -> %d��Low %d -> %d��Cost %d -> %d��",
                                special, lingwu_places[special]["skill"], lw_skill["skill"],
                                lingwu_places[special]["up_limit"], lw_skill["up_limit"],
                                lingwu_places[special]["low_limit"], lw_skill["low_limit"],
                                lingwu_places[special]["cost"], lw_skill["cost"]));
                        lingwu_places[special] = lw_skill;
                }
        }
        special = 0;
        
        /* Wrong s*/
        if( lw_skill["skill"] != arg )
                return notify_fail("�ڴ����� " + arg + " ��Ӧ���� " + lw_skill["skill"] + " �Ŷ԰���\n");
        
        /* have no enbaled this skill */        
        if( !stringp(special = me->query_skill_mapped(arg)) )
                return notify_fail("��ֻ�ܴ����⼼��������" + to_chinese(arg) + "�����⡣\n");
                
        special_lvl = me->query_skill(special, 1);
        
        if( basic_lvl > special_lvl )
                return notify_fail("���"+to_chinese(special)+"���費�����޷��������һ���"+to_chinese(arg)+"��\n");
                
        special = to_chinese(special);
        
        me->start_busy(2);      
        
        if( lw_skill["low_limit"] > me->query_skill(arg, 1) ){
                message_vision("$N��ͷ��˼���ɾ����벻͸�й�" + to_chinese(arg) + "�����⡣\n", me);
                return notify_fail("��о��Լ����޷������е���˼����������������С�\n");   
        }
        
        if( lw_skill["up_limit"] < me->query_skill(arg, 1) ){
                message_vision("$N����һЦ�������Ѷ�" + to_chinese(arg) + "����������ָ���ˡ�\n", me);
                return notify_fail("��о��Լ��ڴ����޷����򵽸��ߵľ����ˡ�\n");   
        }

        // Should be 10..30
        i = lw_skill["cost"];
        if( !i ) i = me->query("int");
        if( i <= 5 ) i = 5;
        i = basic_lvl / i * 10 ;
        
        if( me->query("jing") < i )
                return notify_fail("��Ŀǰ�ľ��񻹲�������һ����ѧ���衣\n");   
        
        if( stringp(str = lw_skill["lw_msg"]) ){
                str = replace_string( str, "$s", special );
                str = replace_string( str, "$b", to_chinese(arg) );
                message_vision(str, me);
        }
        else    message_vision("$N��ʼ�����Լ���" + special + "��Ǳ������" + to_chinese(arg) + "�йص���ѧ���⡣\n", me);
        
        //add for ggss improve
        
        me->set_temp("pending/lingwu", cnt);    
        me->set_temp("lingwu_cost", i);
        me->set_temp("lingwu_type", arg);
        me->start_busy((: start_lingwu :), (:halt_lingwu:));
        return 1;
}

void remove(){  save(); }

int start_lingwu(object me)
{
        int cnt, cost, temp, zstemp;
        string skill;
        
        if( !me ) return 0;
        if( !living(me) ) return 0;
        
        cost = me->query_temp("lingwu_cost");
        if( cost < 20 ) cost = 20;
        cnt = me->query_temp("pending/lingwu");
        skill = me->query_temp("lingwu_type");
        temp = me->query_skill("literate",1) + me->query_int() * 10;

        //�츳����ͯ������Ӱ��Ч��   by lsxk@hsbbs 2008/3/14
        if((int)me->query("relife/study/stzs",1) > 0)
            zstemp = temp + temp * (int)me->query("relife/study/stzs",1) * 2 / 100;
        
        me->receive_damage("jing", cost, "��Ѫ�ݽ�");
        
        if( !living(me) || !stringp(skill) ) return 0;
        
        if (me->query("registered") ==3 && me->query_temp("ggs/started") && me->query("ggs/started")){
            if((int)me->query("relife/study/stzs",1) > 0){
                tell_object(me,HIG"��ֻ�����Լ��츳���ˣ���������Զ�ȱ��˸߳��ܶ࣡\n"NOR);
                me->improve_skill(skill, zstemp);
            }
            else
                me->improve_skill(skill, temp);
        }
        else{
            if((int)me->query("relife/study/stzs",1) > 0){
                tell_object(me,HIG"��ֻ�����Լ��츳���ˣ���������Զ�ȱ��˸߳��ܶ࣡\n"NOR);
                me->improve_skill(skill, zstemp/2);
            }
            else
                me->improve_skill(skill, temp/2);
        }
        me->add("potential", -1);
        if( me->query("potential") < 1 || cnt < 1 || me->query("jing") <= cost ){
                write("���Ѿ�����һ�����ˡ�\n");
                message_vision("$N������ϣ�վ��������\n", me);
                me->delete_temp("pending/lingwu");             
                me->delete_temp("lingwu_cost");
                me->start_busy(1);
                return 0;
        }
        
        cnt--;
        me->set_temp("pending/lingwu", cnt);
        
        switch(random(7)){
                case 6:
                case 3:
                        me->add("potential", -1);
                        if( me->query("potential") > 1 )
                                me->add("potential", -1);
                        if( !random(3) )
                                write("���˼���룬��"+to_chinese(skill)+"�����������һ�㡣\n");
                        me->improve_skill(skill, me->query_skill("literate",1) + me->query_int() * 10 );
                        break;
                case 5:
                case 2:
                        me->add("potential", -1);
                        if( !random(3) )
                                write("�����ֱȻ��ţ���"+to_chinese(skill)+"������ּ�����һ�㡣\n");
                        me->improve_skill(skill, me->query_skill("literate",1)/2 + me->query("int")*5 );
                        break;
                case 4:
                case 1:
                        if( !random(3) )
                                write("��ʾ���֭����Ȼ�޷���ͨ�й�"+to_chinese(skill)+"�����⡣\n");
                        me->improve_skill(skill, me->query_int() * 4);
                        break;
                case 0:
                        if( !random(3) )
                                write("�����˰��죬ȴ�����޷������ͷ������\n");
                        me->improve_skill(skill, random(50));
                        break;
        }
        if (me->query("registered") ==3 && me->query_temp("ggs/started") && me->query("ggs/started") ){
                if (!random(5) ) write("������Լ���"HIG"�������"NOR"�ϵ���Ϊ������ͨ���������Լ����������°빦����\n");
                if (!random(10)) tell_room(environment(me), me->name() + "���ڲ���"HIG"�������"NOR"�ϵ���Ϊ������ͨ���������й�" + to_chinese(skill) + "�����⡣\n", ({ me }));
        }
        //add for ggss improve msg
        return 1;
}

int halt_lingwu(object me)
{
        if( !me ) return 1;
        
        if( environment(me) && me->query_temp("pending/lingwu") ) { 
                if( living(me) )
                        message_vision("$Nüͷ���������������򲻵�Ҫ�죬��������վ��������\n", me);
                me->receive_damage("jing", me->query("jing")/2, "��Ѫ�ݽ�");
                me->delete_temp("pending/lingwu");             
                me->delete_temp("lingwu_cost");
                me->start_busy(2+random(2));
                return 1;
        }
        else return 0;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : lingwu <����> [����]

���ָ������������ض��ص�������ѧ���ܡ�

����    �ڶ���ɽ�����£����� lingwu dodge  �� 100 ���� 200 ����
        �ڶ���ɽ�׶�ƺ������ lingwu force  �� 150 ���� 200 ����

�������ĵ��Ǿ���ÿ��������٣�Ҫ�����˵����Ժ���ѧ�����ˡ�

HELP
        );
        return 1;
}

