#include <ansi.h>
inherit ITEM;
#define TASKREWARD_D "adm/daemons/jobrewardd"
void create()
{
        set_name(HIR"����"NOR, ({"qiu che","che"}));
        set("unit", "��");
        set("long", "����һ��Ѻ�ⷸ�˵�����������������һλ����־ʿ��\n");
        set("value", 0);
        set("no_get",1);
    set("location",1);
//����Ӧ����ˢ�����ڰ�
        setup();
}

void init()
{
  	
  	add_action("do_jie", "jie");
       add_action("do_save", "jiu");

}
int do_jie(string arg)
{
	object me=this_player() , ob , bb;

	if (!arg) return notify_fail("��Ҫ��ʲô��\n");

if (!me->query("jn/qiuche"))
return notify_fail("��û�°ɣ������ı�����������\n");	
if (me->query_temp("jn/jie"))
return notify_fail("��������ɹ��ˣ��������ˣ�\n");

message_vision(HIC"$N"HIC"һʱ�����ŷ�����ֱ��ǰ�ߺ�������͢��ӥצ���ǣ�ʶ��Ŀ콫�����˷��ˣ�\n"NOR,me, ob);
message_vision(HIC"\n���»�������֮��һ㶣����룺�����в��ɣ�\n"
"���������֮�룬���²����������׷���ǰ����$NΧ�ڵ��¡�\n",me,ob);
me->set_temp("jn/jie",1);
bb = new("quest/jqc/guard");
bb->do_copy(me,0);
bb->move(environment(me));
me->kill_ob(bb);
bb->kill_ob(me);
bb = new("quest/jqc/guard");
bb->do_copy(me,0);
bb->move(environment(me));
me->kill_ob(bb);
bb->kill_ob(me);
bb = new("quest/jqc/guard");
bb->do_copy(me,0);
bb->move(environment(me));
me->kill_ob(bb);
bb->kill_ob(me);

return 1;
}
int do_save(string arg)
{
object me=this_player() , ob,bb;
if (arg!= "��") 
return notify_fail("��Ҫ��ʲô��\n");
if (!me->query("jn/qiuche") || !me->query_temp("jn/jie")) 
return notify_fail("��û�°�!!!�����ı�����������\n");	
if(present("gao shou"))
return notify_fail("��͢ӥȮ���ڣ�����ô���ˣ�\n");
if(me->is_fighting()) return notify_fail("ս�����ڲ����������ˡ�\n");
TASKREWARD_D->get_reward(me,"������",1,0,0,20,0,0,0,this_object());
message_vision(HIC"$N"HIC"�첽��ǰ�ҿ������������ڵ��˾��˳�����\n"NOR,me, ob);
message_vision(HIC"\n����־ʿ����$N��ȭһ��˵�������������¸��֮��\n"
"�����Ѿ��Ի�����˵�ձ�Ҵ���ȥ��\n",me,ob);
me->delete("jn/qiuche");
me->delete("jn/time");
me->delete_temp("jn/bb");
me->delete_temp("jn/jie");
me->set("job_name","������");
destruct(this_object());
me->delete("jn/qiuche_ob");
me->delete("jn/qiuche_super");
me->apply_condition("jn_job",40);
me->apply_condition("job_busy",1);
return 1;
}



void dest()
{
        write(HIW"�����������ڴ��ڸ��ֵĻ������뿪�ˡ�\n"NOR);
	destruct(this_object());
}
