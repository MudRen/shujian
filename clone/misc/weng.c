#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(CYN"����"NOR, ({ "wa weng", "wa" ,"weng"}) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ���������ɵ��ͣ�����ڶ����ģ������˱��ƺ�װ��ʲô���\n"
);
                set("unit", "��");
                set("value", 80);
set("no_get",1);
set("no_give",1);
set("no_cun",1);
               
}
}
void init()
{
        add_action("do_shenshou", "shenshou");
}

int do_shenshou(string arg)
{
object me,ob;
me = this_player();
ob = this_object();

if(ob->query("owner")!=me->query("id"))
return notify_fail("�����Ū���Ķ�����\n");

if (!arg)
 return notify_fail("��Ҫ��ʲô?\n");

if (arg!="wa weng" && arg!="wa" && arg!="weng")
return notify_fail("��Ҫ���������֣�\n");
if ( !present("fanwen book", me)) return 0;
message_vision(HIR"$Nҧ�����ݣ������۾������������������͡�\n"NOR,me);
message_vision(HIR"$N��ָһ�������У���ָָ���ϱ�����̰�\n"
                    "��Ȼ��ʹ���̲�ס����һ����ֻ��һ������\n"
                    "��ҧס���Լ���ָ��ԭ��������Ѫ...\n"NOR,me);
me->start_busy(999);
 remove_call_out("thinking");
           call_out("thinking",3, me );

return 1;
}

int thinking(object me)
{
if(!me) return 0;
if ( !present("wa weng", me)) return 0;
if ( !present("fanwen book", me)) return 0;
tell_object(me,HIB"\n��ȫ��ë,���д󺧡����ڱ�����Ѫ��������ʹ�������Ǳ���\n"
                    "�����״��������Լ�����ָ��ȴҲ����������һ������֮ɫ��\n"
                    "��ɫ��ǳ�������ת����ڣ��ٹ�һ�ᣬ��ɫ��ָ���ƣ���\n"
                    "�������ֱ�����������ʱ�ѽ�����˦�˳�ȥ��������̹֮Ȼ����\n"
                    "�Ǳ�Ҳ΢΢¶��Ц��...\n"NOR);


remove_call_out("thinking1");
call_out("thinking1",4, me );
}

int thinking1(object me)
{
if(!me) return 0;
if ( !present("wa weng", me)) return 0;
if ( !present("fanwen book", me)) return 0;
tell_object(me,HIB"\n����ʱ��ֻ��һ��������������Ҹ�ѣ�ͬʱһ���ֱ�Ҳ����������\n"
                    "��ʱ֮�䣬����ǧ��ֻ������ͬʱҧ��һ�㡣\n"NOR);

tell_object(me,HIB"\n��������У���������������ȥɦ��һɦ֮�£���������������\n"
                    "���ƹ����С��ķ��ж��г������˽�ȥ�����������ʹ���̶�\n"
                    "�������ͣ����������£�������У���ͷ������ײǽ�ڣ�����\n"
                    "���죬ֻ���Լ���ʱ���˹�ȥ��ʧȴ֪������������Ѱ���������\n"NOR);

remove_call_out("thinking2");
call_out("thinking2",5, me );
}

int thinking2(object me)
{
if(!me) return 0;
if ( !present("wa weng", me)) return 0;
if ( !present("fanwen book", me)) return 0;
tell_object(me,HIB"\n��ײ�ü��£�ž��һ�������е���һ�����£�����ʰ�����Ǳ�\n"
                    "���ľ��顣��ʱ����֮�£�Ҳ�˲���ȥʰ������������з�����\n"
                    "��ȫ��˵�������Ѱ��������ڵأ��Ҳ���ײ������һ�ᣬ����\n"
                    "��ֻ�Ǵ�Ϣ����ˮ�����顢���Ѷ�������������������ھ����ϡ�\n"
                    "��������Ҳ��֪���˶���ʱ����ҳ���ѽ�����������Һ��\n"
                    "������һƳ��������ҳ�ϵ���������������֮�䣬���ֳ�һ��\n"
                    "���֣���Ħ٤�ӹ�����Ħ�ض��гɾ����㾭������Щ����Ҳʶ\n"
                    "����ȫ���ּ��������и����ɮ��ͼ�Ρ���ɮ����ʽ���أ���\n"
                    "���ӿ��´��������˳�����˫��ץ����ֻ�š�\n"NOR);

remove_call_out("thinking3");
call_out("thinking3",5, me );
}

int thinking3(object me)
{
object ob,ob1;
if(!me) return 0;
if ( !present("wa weng", me)) return 0;
if ( !present("fanwen book", me)) return 0;
tell_object(me,HIB"\n��Ҳû����ȥ�������ϵĹŹ����ƣ�ֻ�����ü�����Ҳ͸������\n"
                    "�ˣ����ڵ��£���˺���������������ºͿ���˺��ƬƬ���飬��\n"
                    "����������������Ħ��������Ƭ�̣�Ƥ���б�����Ѫ�������ҹ�\n"
                    "�Ҳ���ͻȻһ��С�ģ��Դ�����˫�ȼ䴩����������Ȼ��Ȼ��ץ\n"
                    "ס���ҽš�\n"NOR);

tell_object(me,HIB"\n����������ƺ���������֮����һ���޶���͸��ȴ˳���ö��ˡ�\n"
                    "����Ҳ������Ҫ���Դ��ӿ���������������ô���ڵ��£�������\n"
                    "��ͼ��ɮ�����ƣ�������Ҳȥ��ס����ţ����ֵء���ôһ����\n"
                    "��������ͼ�е�ɮ�����죬͸����������ˡ�\n"NOR);

tell_object(me,HIB"\n�㾪��֮�£�Ҳ��Ͼȥ������ԭ��ֻ���������������ʮ��\n"
                    "��ʱ�������ѽ���΢��������ʮ��Σ���ָ�����ơ��ֱ۸�����\n"
                    "ȫ����С�\n"NOR);
if( random(me->query("kar"))> 28  && random(15)==1 && me->query("buyvip"))
{
remove_call_out("thinking4");
call_out("thinking4",5, me );
}
else 
tell_object(me,HIG"\n��������������˼���ã���֪����Ǻ�....\n"NOR);
message_vision(HIC"\n$Nҡ��ҡͷ�������̾�˿�����\n"NOR,me); 
tell_object(me,HBBLU"\n�ܿ�ϧ���㱾�γ��Ա��϶��ƽ���ʧ�ܣ�\n"NOR);
tell_object(me,HBBLU"�����Ŭ����\n\n"NOR);
log_file("quest/bingcan",sprintf("%8s%-10s���Խ⿪���϶�������ʧ�ܣ����飺%d������%d��������%d��\n",
me->name(),"("+me->query("id")+")", me->query("combat_exp"),
me->query("kar"), me->query("quest/bingcan/fail")), me);


me->add("quest/bingcan/fail",1);
me->delete_temp("waweng");
me->start_busy(3);
me->add("qi",-me->query("max_qi")*2/5);
me->add("eff_qi",-me->query("max_qi")*2/5); 
destruct(present("fanwen book", me));
destruct(present("wa weng", me));
return 0;
}

int thinking4(object me)
{
if(!me) return 0;
if ( !present("wa weng", me)) return 0;
if ( !present("fanwen book", me)) return 0;
tell_object(me,HIW"\nͻȻʳָ����΢΢һ����һ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ��\n"
                    "���׵��������ţ������ԡ�����Ħ�ض��гɾ����㾭�����˹�\n"
                    "֮�������ⶾ����ѪҺΪ�����������ں��ֻ�������ָѪ�ܣ�\n"
                    "����綾�ޱȵı��Ϻ������������ڡ�\n"NOR);
  
tell_object(me,HIY"\n��������������˼���ã���Ȼ����....\n"NOR);
message_vision(HIC"\n$N�������������ӻָ������ѡ�\n"NOR,me); 
tell_object(me,HBBLU"\n��ϲ�㣬�������ˡ����϶��ơ���\n"NOR);
me->set("quest/bingcan/pass", 1);
                me->set_skill("bingcan-duzhang",10+random(5));
                
                tell_object(me,HIC"��ı��϶��ƽ����ˡ�\n", me);
log_file("quest/bingcan",sprintf("%8s%-10s�ɹ��⿪���϶������ܣ����飺%d������%d��������%d��\n",
                        me->name(),"("+me->query("id")+")", me->query("combat_exp"),
                        me->query("kar"), me->query("quest/bingcan/fail")), me);                 
destruct(present("fanwen book", me));
destruct(present("wa weng", me));
return 1;
}
