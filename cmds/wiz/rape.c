// rape.c
// by hongba
#include <ansi.h>
void post(object me, object obj);
void sec_post(object me, object obj);
void trd_post(object me, object obj);
void over(object me, object obj);
void over1(object me, object obj);


int main(object me, string arg)
{
	object obj, *ob,where;
	int i;
if( me->is_busy() )
		return notify_fail("����æ���ء�\n");

	if ( !arg || !objectp(obj = present(arg, environment(me)))) return notify_fail("���롰����˭��\n");

	if ( !obj->is_character() || me->query("gender") == obj->query("gender") || obj->query("race")=="Ұ��" )
		return notify_fail("�������㶼���ϣ���ζ���ذ���\n");

	if ( !living(obj)) return notify_fail("�˼Ҷ������ˣ��㻹...\n");

	
	if ( me->query("gender") == "Ů��" && me->query_condition("pregnant") )
		return notify_fail ("���Ǹ�Ů��ѽ����ô��˴󷽣�\n");

	if ( obj->query("gender") == "Ů��" && obj->query_condition("pregnant") )
		return notify_fail ("�˼��Ѿ������ˣ���Ҫ��������ɹ����̵�\n");

		if ( (int)me->query("age", 1) < 18 ) return notify_fail ("С���ͺ��ӹ�Զ�㣡\n");
if( me->query("gender") =="����" )
                return notify_fail("��һ����̫�࣬Ҳ��Ū�������\n");


	if ( (int)obj->query("age", 1) < 18 ) return notify_fail ("�۸���ôС�ĺ��ӣ�����Ҫ������������\n");
if( obj->query("raped") > 5) 
return notify_fail ("���Ů�˶����ˣ���Ҳ���ϣ�\n");
// ��ǿ�����5�ξ������˼Ұ�

	
	where=environment(me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
		if( ob[i]->is_character()&&ob[i] != me && ob[i]!=obj&&!wizardp(ob[i]) )
			return notify_fail("���컯�գ�����Ǭ������ô�����ڣ���Ͳ���������\n");

				message_vision(HIC "$N���Ĵ���$n���ͻȻ��$n����§ס��\n" +
				"��$n�����׺ݵ�˵����С�Թԣ��ô�үˬˬ����\n"NOR, me, obj);
CHANNEL_D->do_channel( this_object(), "rumor", sprintf("%s(%s)��%s����ǿ��%s�����˹�û�˹ܣ�����\n",
			me->name(1),getuid(me),(string)where->query("short"),obj->name(1)			
			));

me->start_busy(999);
obj->start_busy(999);

						call_out("post", 3, me, obj);
return 1;
}

void post(object me, object obj)
{
	message_vision(HIC"\n$nת���Ҫ�����$Nһ����ס��\n"NOR,me,obj);
message_vision(HIC"\n����$n��$N������ס��û��������ֻ����$N�׸��ˡ�\n"NOR,me,obj);


	call_out("sec_post", 3, me, obj);
}

void sec_post(object me, object obj)
{
	message_vision(HIC"\n���ڽ�����ߣ�$N���̲�ס��ϸ������$nһ�¡�\n"NOR, me, obj);
message_vision(HIC"\n$N���������������˿���û��ע�⣬���ɵ�.....��\n"NOR, me, obj);

	call_out("trd_post", 4, me, obj);
}

void trd_post(object me, object obj)
{
	message_vision(HIW"\n��һ���,$N��Ҳ������ס���е����𣬽�$n���ϵ�����һ��һ���س��¡�\n\n"NOR, me, obj);
if(obj->query("marry/id") ){
message_vision(HIY"\n��˵�Ѳ����Ǵ�Ů,����Ϊ�ٸ���$n�Ƿ�������������Ҳ���㴹������!\n"NOR, me, obj);
message_vision(HIC"\n����$Nһ�ѽ�$n�����ڵ��ϡ���������\n"NOR, me, obj);
message_vision(HIC"\n���ܳ����$N��Ұ�ް�ĺ������$n˺���ѷεĿ���������\n"NOR, me, obj);

call_out("over", 3, me, obj);
}

else {
message_vision(HIM"\n$n����������Ů���㣬�ò���$N�������ߣ���Ҳ�ȴ�������\n"NOR, me, obj);
message_vision(HIC"\n����$Nһ�ѽ�$n�����ڵ��ϡ���������\n"NOR, me, obj);
message_vision(HIC"\n���ܳ����$N��Ұ�ް�ĺ������$n˺���ѷεĿ���������\n"NOR, me, obj);

call_out("over", 4, me, obj);

}

	
}

void over(object me, object obj)
{
       	message_vision(HIR"���ã���ͣ��Ъ����������\n"NOR, me,obj);
if(obj->query("marry/id") || obj->query("raped") ){
message_vision(HIY"\n$N�������������Ż�˯�ڵص�$nʧ����̾��һ������������ĵ�ù,��������������'ˮ��'��\n"NOR, me, obj);
message_vision(HIC"\n��ʱֻ��$Nҡҡ�λΣ����㲻�ȡ�\n"NOR, me, obj);
message_vision(HIC"\nԭ���㷢���Լ�ȫ��������������Ĺ����ˣ�

\n\n"NOR, me, obj);
}
else {
message_vision(HIG"\n$N�������������Ż�˯�ڵص�$n�����ؽе����ٺ٣����Ǹ��ƻ���Ů�������Ӽ��˸�����ˡ�\n"NOR, me, obj);
message_vision(HIC"\n��ʱֻ��$Nҡҡ�λΣ����㲻�ȡ�\n"NOR, me, obj);
message_vision(HIC"\nԭ��$N�����Լ�ȫ��������������Ĺ����ˣ�\n"NOR, me, obj);
me->add("jing",-1000);
}

CHANNEL_D->do_channel(this_object(), "rumor", obj->name(1)+"��" 
	    + me->name(1)+"��"+environment(me)->query("short")
	    + "ǿ����!");
CHANNEL_D->do_channel(this_object(), "rumor", me->name(1)+"���ٸ�ͨ����" 
	    );


me->apply_condition("killer",500); 


call_out("over1", 3, me, obj);

}
void over1(object me, object obj)
{
/*
 message_vision(HIR"\n$n����������������������۵ض���$N���һ��:"+me->query("rank_info/rude")+"���ӣ����������壬������������,
���Ժ���ƴ�ˣ�\n"NOR, me, obj);
*/
message_vision(HIR"\n$n����������������������۵ض���$N���һ��:�������ӣ����������壬������������,���Ժ���ƴ�ˣ�\n"NOR, me, obj);
obj->add("raped",1);  // ��ǿ��Ĵ���
me->start_busy(10);
obj->start_busy(4);
obj->kill_ob(me);
me->fight_ob(obj);
}




	
int help(object me)
{
	write(@HELP
ָ���ʽ : rape <����>
�������޷粻����,�����������������ٲ��˲ɻ����ģ�
���ӹ�������µ��ﲮ���,������������������ǵ�.
�����ɻ�����������Ϊ����,���һ�Ҫ������ֵ��ִ�����
û��һ���汾��,���е��ܲ��ˡ�
�е���'���в�����Ա�'����֮����֮����֮��
��Ȼ���˾���ĪΪ֮��
HELP);
	return 1;
}
