// abandon.c
// Motify by snowman at 19/03/1999.
// ������ȷ����

#include <ansi.h>

int help();
private void delete_skill(string arg, object me, string skill, int level, int lvl);

int main(object me, string arg)
{
int level, lvl = 0;

if (!arg)
return notify_fail("ָ���ʽ��abandon|fangqi <��������> [����]\n");

sscanf(arg, "%s %d", arg, lvl);
  
if (!me->query_skills() || undefinedp(me->query_skills()[arg]))
return notify_fail("�㲢û������ܡ�\n");

level = me->query_skill(arg, 1);

if (!intp(lvl) || lvl < 0) 
return notify_fail("��������Ϊ������\n");

if (me->is_busy())
return notify_fail("����æ���ء�\n");
me->start_busy(1);
if (!lvl) lvl = me->query_skill(arg, 1);
if (lvl >= level) {
if (lvl < 60) {
me->delete_skill(arg);
write("\n�������"+ to_chinese(arg) +"��\n\n");
} else {
write("\nע�⣡�㽫Ҫ����ȫ�� "HIW + to_chinese(arg) + "("+arg+")"NOR" ��ȷ����[Y|N] >");
input_to("delete_all", me, arg, lvl);
}
} 
else if (level < 100)
return notify_fail("������ܻ�û�е����շ�����ĵز���\n");
else {
write("\nע�⣡�㽫Ҫ����" + chinese_number(lvl)+ "�� "HIW+to_chinese(arg)+"("+arg+")"NOR" ��ȷ����[Y|N] >");
input_to("delete_skill", me, arg, level, lvl);
}
return 1;
}

private void delete_all(string arg, object me, string skill, int lvl)
{
if( arg[0]=='y' || arg[0]=='Y' ){
me->delete_skill(skill);
if(userp(me) && !wizardp(me) && lvl >= 60)
log_file("static/ABANDON", sprintf("%s(%s) ������ȫ�� %d �� %s �� %s\n",
me->name(1), me->query("id"), lvl, to_chinese(skill) , ctime(time()) ));
write("\n�������"+ to_chinese(skill) +"��\n\n");
}
else write("\n���������"+ to_chinese(skill) +"("+skill+")��\n\n");
}

private void delete_skill(string arg, object me, string skill, int level, int lvl)
{
if( arg[0]=='y' || arg[0]=='Y' ){
me->set_skill(skill, level - lvl);
if(userp(me) && !wizardp(me) && lvl >= 60)
     log_file("static/ABANDON", sprintf("%s(%s) ������ %d �� %s �� %s\n",
  me->name(1),me->query("id"), lvl, to_chinese(skill) , ctime(time()) ));
write("\n�������" + chinese_number(lvl)+ "��"+ to_chinese(skill) +"("+skill+")��\n\n");
}
else write("\n���������"+ to_chinese(skill) +"("+skill+")��\n\n");
}

int help()
{
write("
ָ���ʽ��abandon|fangqi <��������> [����]

����һ������ѧ���ļ��ܣ�ע��������˵�ġ���������ָ������ܴ�������
��������ɾ����������Ժ�Ҫ��������ӣ���ʼ����������ؿ��������

���߿���ѡ�����ָ���ļ�������Χ������ 1 �����м���֮�����Ŀ�����ڼ�
����ζ��ȫ��������

���ָ��ʹ�õĳ���ͨ��������ɾ��һЩ����С�ġ��������ļ��ܣ�����ÿ��
�����Ų�ͬ���츳������ϰ���书Ҳ������ͬ�����������ѧ����ͷ��ֻ����
��������

���� abandon dodge 10.      ���� 10 �������Ṧ��
     abandon dodge. ���������Ṧ��
     

ע�⣺��ʦ����ָ���������书��һ�к���Ը���
     
\n");
return 1;
}
