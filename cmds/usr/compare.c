// ��ʵս���� �������ֵ ������ ������ str con �� ɱ��
// �Թ�ʽ�жϵ��� ������ ʵ�����֮���� 


#include <ansi.h>
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object ob, string str)
{
	int range,range1,range2,range3;
	int ex1,ex2,ke1,ke2,se1,se2,wc1,wc2,be1,be2,dz1,dz2;
	int at1,at2,st1,st2,co1,co2,force1,force2,mana1,mana2;
	object me = this_player();
	
	ex2 = me->query("combat_exp");
	ke2 = (int)me->query("max_jing");
	se2 = (int)me->query("max_jingli");
	force2 = (int)me->query("max_neili");
	mana2 = (int)me->query("max_qi");
	wc2 = (int)me->query_temp("apply/armor");
	at2 = (int)me->query_temp("apply/damage");
	st2 = (int)me->query("str");
	co2 = (int)me->query("con");
	be2 = (int)me->query("int");
	dz2 = (int)me->query("dex");

	range1=(force2/2+mana2/2+ex2/4+ke2+se2+wc2*2+be2+dz2+at2*2+st2+co2);

	    if(!str) {
		notify_fail("ʹ�÷��� : <compare [����]>\n");
		return 0;
	    }
	    ob = present(str,environment(me));
	    if(!ob) {
		notify_fail(str+" ��������\n");
		return 0;
	    }
		if( !ob->is_character() || ob->is_corpse() || ob->is_ghost() )
	       	return notify_fail("�����һ�㣬�ǲ����ǻ��\n");//By waiwai@2001/05/05 changed.
	
	    if(ob==me) {
	        notify_fail("�Լ����Լ��ȽϵĽ����һ���ġ�\n");
	        return 0;
	    }
	ex1=ob->query("combat_exp");
	ke1=(int)ob->query("max_jing");
	se1=(int)ob->query("max_jingli");
	force1=(int)ob->query("max_neili");
	mana1=(int)ob->query("max_qi");
	wc1=(int)ob->query_temp("apply/armor");
	at1=(int)ob->query_temp("apply/damage");
	st1=(int)ob->query("str");
	co1=(int)ob->query("con");
	be1=(int)ob->query("int");
	dz1=(int)ob->query("dex");
	
	range3=((ex1+ex2)/200);
	
	range2= (se1+force1/2+mana1/2+ex1/4+ke1+wc1*2+be1+dz1+at1*2+st1+co1);

	if(wizardp(me)) printf("range3=%d\n",range3);
	if(!range3) range3=1;
	if(!range2) range2=1;

	range= ((range2/range3)-(range1/range3));

	if( userp(ob) ) {
	
	if( time()-me->query_temp("compare_time")<0) {
        notify_fail("�벻ҪƵ��ɧ�ű��ˡ�����\n");
        return 0;
	} else {
	tell_object(ob,
	YEL"��ͻȻ�е�����" WHT+ me->name() +NOR YEL "���ڹ�������̽���㡭��\n"NOR);
	me->set_temp("compare_time",time()+180);

       }
	}
       write("����ϸ����ǰ������"+HIG+ob->name()+NOR+"һ����\n");
       if(range < - 30) {
       write("��Ҫɱ��"+HIG+ob->name()+NOR+"����Ҫ�������ϰ����ס�\n");
	write("���Ա�����Ϊ�ж�"+HIG+ob->name()+NOR+"�Ľ���������Լ��"HIR"�����������"NOR"�ļ�����\n");
       return 1;
    }
       if(range < -25) {
      	write("�۹�������, "+HIG+ob->name()+NOR+"����������������Ķ���!\n");
	write("���Ա�����Ϊ�ж�"+ob->name()+"�Ľ���������Լ��"HIR"��ͨ�������"NOR"�ļ�����\n");
	return 1;
     }
     if (range < -20) {
	write("��о�"+HIG+ob->name()+NOR+"�����Ǹ������, ������мһ�ˡ�\n");
	write("���Ա�����Ϊ�ж�"+HIG+ob->name()+NOR+"�Ľ���������Լ��"HIC"С����"NOR"�ļ�����\n");
         return 1;
     }
       if (range < -15) {
	write("��Ȼ�Ӹ����濴���㶼��"+HIG+ob->name()+NOR+"��ʤһ��, ����Ҳ������С�\n");
	write("���Ա�����Ϊ�ж�"+ob->name()+"����������Լ��"HIC"��ͨ��ɫ"NOR"�ļ�����\n");
      return 1;
     }
        else if(range < -5) {
	write("��о�"+HIG+ob->name()+NOR+"�����ƾ�����, ��������һ������������\n");
	write("���Ա�����Ϊ�ж�"+HIG+ob->name()+NOR+"�Ľ���������Լ��"HIY"�������£�����֮��"NOR"�ļ�����\n");
       return 1;
      }
      else if(range < 10) {
	write("��о�"+HIG+ob->name()+NOR+"����ǿһ��, �����Ҫ�г�ݵ�׼������ʤ�㡣\n");
	write("���Ա�����Ϊ�ж�"+ob->name()+"�Ľ���������Լ��"HIY"��ͨӲ��"NOR"�ļ�����\n");
          return 1;
       }
       else if(range < 20) {
       write("С�ĵ㣬"+HIG+ob->name()+NOR+"������ʤһ��, ���ʤ�㲻��\n");
	write("���Ա�����Ϊ�ж�"+HIG+ob->name()+NOR+"�Ľ���������Լ��"HIY"һ�����"NOR"�ļ�����\n");
       return 1;
       }
        else if(range < 25) {
       write("С�ĵ㣬"+HIG+ob->name()+NOR+"���Ǻ�Ӳ���, �û�һ������\n");
	write("���Ա�����Ϊ�ж�"+HIG+ob->name()+NOR+"�Ľ���������Լ��"HIM"���ָ���"NOR"�ļ�����\n");
       return 1;
	}
        else if(range < 30) {
          write("���˰�, Ҫ�� "+HIG+ob->name()+NOR+" ���ٻ�ȥ����ʮ�ꡣ\n");
          write(HIC"�㿪ʼ�о���һ��ǿ�����Ϣ����ƽ���\n"NOR);
	  write("���Ա�����Ϊ�ж�"+HIG+ob->name()+NOR+"�Ľ���������Լ��"HIM"��ɲ�"NOR"�ļ�����\n");
        return 1;
       }
       else if(range <35) {
          write("ƾ���ʵ�����"+ob->name()+", ��ֱ��������졣\n");
	write(HIY"��о���һ��ʮ��ǿ�����Ϣ�����Ƚ���\n"NOR);
	write("���Ա�����Ϊ�ж�"+HIG+ob->name()+NOR+"�Ľ���������Լ��"HIW"��ǰ����"NOR"�ļ�����\n");
         return 1;
      } else {
	write("�������� , ֱ��ȥ��ɱҲ����㻹�ȽϿ��, "+HIG+ob->name()+NOR+"��ʵ����ɲ�!\n");
	write(HIY"��о���ʮ�־��˵�������ɱ����"+HIG+ob->name()+HIY+"����ɢ��������\n"NOR);
	write("���Ա�����Ϊ�ж�"+HIG+ob->name()+NOR+"�Ľ���������Լ��"HIW"����������ױ�"NOR"�ļ�����\n");
       return 1;  
    }
}

int help()
{
write(@LONG

ָ���ʽ : compare [����]
ָ��˵�� : �Ƚ���ͶԷ���ǿ��

����������
�����Ѫ����󾫣���������������
���������ǣ����ԣ��������ױ���

LONG);
	return 1;
}

