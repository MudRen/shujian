#include <ansi.h>

int main(object me, string arg)
{
	if (!arg) return notify_fail("�����뺺�֡�\n");

	if (strlen(arg) > 20) return notify_fail("̫���ˡ�\n");
	write("\n"+HIY+CHINESE_D->font(arg)+NOR);
	write("\n"+HIY+CHINESE_D->chinese_graph_font(arg)+NOR);
	return 1;
}
