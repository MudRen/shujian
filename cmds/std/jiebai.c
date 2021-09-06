// jiebai.c
#include <ansi.h>
#include <dbase.h>
inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{
        object obj, old_target;
	mapping my;
	string x, title, title1;
	my = me->query_entire_dbase();

	if (me->query("title")) title = me->query("title");
	else title = "��ͨ����";

        if(me->query("age") < 16)
                return notify_fail("С����һ�����ȥ��\n");

        if(!arg ) { help(me); return 1;}
	
	if( sscanf(arg, "%s %s", arg, x)==2 ) {
		if(x != "/f")
			return notify_fail("����������������ѣ�������"+HIR+"jiebai <ID> /f��"+NOR+"\n");

		if(!objectp(obj = present(arg, environment(me))))
	        	return notify_fail("�����˭��Ŀ��\n");
	
	        if( !userp(obj) )
	                return notify_fail("��ֻ�ܺ��Ѿ��ݰ��ӵ���ҷ�Ŀ�ɳ�\n");
	
	        if( !living(obj) )
	                return notify_fail("��...�㻹���Ȱ�"+obj->name()+"Ū�Ѱɡ�\n");
	
	        if(obj==me)
	                return notify_fail("���Լ���Ŀ��\n");
		
                if ( !me->is_jiebaied()) return notify_fail("�㻹û�н�ݣ�Ҫ��˭��Ŀ��\n");
	
		if ( !me->is_jiebai_of(obj)) return notify_fail("�㻹û�к��˼ҽ�ݣ���Ҫ������Ŀ��\n");
		else{
			if (obj->query("title")) title1 = obj->query("title");
			else title1 = "��ͨ����";

		        message("channel:chat",HIR"����Ŀ�ɳ�"HIC + title + HIC + me->query("name") +"�Ӵ���"+HIC+  title1 +HIC+ obj->query("name")
		                 + "���������\n\n"NOR,users());
			me->delete("jiebai/"+obj->query("id"));
			obj->delete("jiebai/"+me->query("id"));
			me->add("fanmu",1);
			return 1;
		}
	}

        if( me->jiebai_cnt() >= 3 ) 
                return notify_fail("���������Ѿ���̫���ˡ�\n"); 

	if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("�����˭��ݣ�\n");

        if( !obj->is_character() )
                return notify_fail("�����һ�㣬�ǲ��������\n");

        if( !userp(obj) )
                return notify_fail("��ֻ�ܺ���Ұݰ��ӡ�\n");

        if( !living(obj) )
                return notify_fail("��...�㻹���Ȱ�"+obj->name()+"Ū�Ѱɡ�\n");

        if( me->is_spouse_of(obj))
                return notify_fail("����֮�仹Ҫ�����\n");

        if( me->is_marry_of(obj))
                return notify_fail("�������Ѿ������ˣ����ý���˰ɣ�\n");
                
	if( me->is_jiebai_of(obj) )
                return notify_fail("���Ѿ����˼ҽ�ݹ��ˡ�\n");

        if(obj==me)
                return notify_fail("�㲻�ܺ��Լ���ݡ�\n");

        if(me->query_temp("pending/jiebai") == obj)
                return notify_fail("���Ѿ������������󣬵���ͬ��ɣ�\n");

        if( userp(obj) && (object)obj->query_temp("pending/jiebai")!=me ) {
                message_vision(HIC "\n$N����$n˵����" 
                        + RANK_D->query_self(me) 
                        + me->name() + "����"
                        + RANK_D->query_respect(obj) + "�����Ѿã�Ը�˴������빲���ε����գ�\n\n"NOR, me, obj);
                if( objectp(old_target = me->query_temp("pending/jiebai")) )
                        tell_object(old_target, RED + me->name() + "ȡ���˺����ݵ���ͷ��\n" NOR);
                me->set_temp("pending/jiebai", obj);
                tell_object(obj, YEL "�����Ը��ͶԷ���Ϊ���Թ��⣬����Ҳ��" + me->name() + "("+(string)me->query("id")+")"+ "��һ�� jiebai ָ�\n" NOR);
                write(RED "�Է�����ͬ����ܽ�ݡ�����Űɡ�\n" NOR);
                return 1;
        }

	if (obj->query("title")) title1 = obj->query("title");
	else title1 = "��ͨ����";

        message_vision(HIC"\n$N����$n����˵��������ͬ��ͬ��ͬ��������Ըͬ��ͬ��ͬ������\n\n"NOR, me, obj);
        message("channel:chat",HIR"�����������"HIC + title + HIC + me->query("name") +"Ը��"+HIC+  title1 +HIC+ obj->query("name")
                 + "���������\n\n            ����ͬ��ͬ��ͬ��������Ըͬ��ͬ��ͬ������\n"NOR,users());

        me->delete_temp("pending/jiebai");
        obj->delete_temp("pending/jiebai");
        me->set("jiebai/"+obj->query("id"),obj->query("name"));
        obj->set("jiebai/"+me->query("id"),me->query("name"));
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : jiebai <���ID> [/f]
 
���ָ�������ͱ��˵Ľ�ݣ���Ȼ�Է�����Ҳͬ�⡣
������� /f  ��������Ҫ����Ҿ��ѣ������ã�
HELP
    );
    return 1;
}

