// sailing.c ������
// 2/5/2002	by augx@sj

inherit SKILL;
string type() { return "knowledge"; }
void skill_improved(object me) { }
int valid_learn(object me)
{
	return notify_fail("��ֻ����ʵ����ѧϰ����������\n");
}
