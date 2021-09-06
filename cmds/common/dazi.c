#include <ansi.h>

int main(object me, string arg)
{
	if (!arg) return notify_fail("ÇëÊäÈëºº×Ö¡£\n");

	if (strlen(arg) > 20) return notify_fail("Ì«¶àÁË¡£\n");
	write("\n"+HIY+CHINESE_D->font(arg)+NOR);
	write("\n"+HIY+CHINESE_D->chinese_graph_font(arg)+NOR);
	return 1;
}
